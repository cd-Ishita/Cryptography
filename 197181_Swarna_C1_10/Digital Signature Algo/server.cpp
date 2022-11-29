#include <bits/stdc++.h>
#include <arpa/inet.h> 
using namespace std;

int createServer(int port)  // TCP connection
{
    int sersock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(port), INADDR_ANY};

    bind(sersock, (struct sockaddr *) &addr, sizeof(addr));
    cout << "\nThe server is online. \n Currently waiting for the client" << endl;

    listen(sersock, 5);
    int sock = accept(sersock, NULL, NULL);
    cout << "The connection has been established." << endl;
    return sock;
}

long randInRange(long low, long high) // excluding high and low
{
    return rand()%(high-(low+1)) + (low+1) ;
}

long mod(long a, long b)
{
	return a >= 0 ? (a%b) : b-(abs(a)%b) ;
}

long powermod(long a, long b, long  c)
{
    long res=1;
    for(int i=0; i<b; i++)
        res = (res * a) % c;
    return res;
}

long findInverse(long R , long D)
{
    int i = 0;
    long N = D; // copy D to N for taking mod 
    long p[100] = {0,1};
    long q[100] = {0} ;

    while(R!=0)
    {
        q[i] = D/R ;
        long oldD = D ;
        D = R ;
        R = oldD%R ;
        if(i>1)
            p[i] = mod(p[i-2] - p[i-1]*q[i-2], N) ;
        i++ ;
    }
    if (i == 1) 
    	return 1;
    else        
    	return p[i] = mod(p[i-2] - p[i-1]*q[i-2], N) ;
}

long H(long M) // Hash Function
{
	return (M ^ 1234); //hash key = 1234 
}

int main()
{
    int port;  
    cout << "\nEnter port : "; 
    cin >> port;
    int sock = createServer(port);

    long p, q; // prime numbers
    long r, s; // signature
    long k, x, y, g; // keys
    long M, hashval; // Message and Hash
    srand(time(NULL));

    cout << "\nEnter a large prime number, p : ";   
    cin >> p; 
    cout << "Enter any other prime number, q : "; 
    cin >> q;
    if( (p-1)%q != 0 || q <3) 
    { 
    	cout << "\nThe input is invalid\n"; 
    	exit(-1); 
    }

    cout<<"Enter the message, M = "; 
    cin >> M;

    hashval = H(M); 
    cout << "\nThe Hash Code is H(M) = " << hashval << endl;

    long h;
    do
    {
        h = randInRange(1, p-1);        // 1 < h < p-1
        g = powermod(h,(p-1)/q, p);	    //g > 1
    } while(g<=1);
    cout << "The Generator, g    = " << g;

    x = randInRange(1, q);  
    cout << "\nServer's Private key, x = " << x;
    y = powermod(g, x, p);  
    cout << "\nServer's Public  key, y = " << y;
    k = randInRange(1, q);  
    cout << "\nSecret key, k = " << k << endl;

    //Signing
    r = powermod(g, k, p) % q;
    s = (findInverse(k,q) * (hashval + x*r )) % q; 
    cout << "\nServer's Signature {r,s} = {" << r << ", " << s << "}" << endl;

    send(sock, &p, sizeof(p), 0);
    send(sock, &q, sizeof(q), 0);	
    send(sock, &g, sizeof(g), 0);	
    send(sock, &y, sizeof(y), 0);	
    send(sock, &M , sizeof(M), 0);
    send(sock, &r, sizeof(r), 0);
    send(sock, &s, sizeof(s), 0);	

    cout << "\nSuccessfully sent p, q, g, and public key to client.";
    cout <<"\nSuccessfully sent message along with signature to client." << endl << endl;
    
    return 0;
}
