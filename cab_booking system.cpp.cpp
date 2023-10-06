#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
int i,j,k,l,m,n,o,cnt=0,ccnt=0;
using namespace std;
class cab;
class customer;
# define INF INT_MAX
cab *c[100];
customer *cu[100];

///



struct Edge
{
	int u;
	int v;
	int weight;
};

class Graph
{
	int V ;
	list < pair <int, int > >*adj;

	vector < Edge > edge;

public :
	Graph( int V )
	{
		this->V = V ;
		adj = new list < pair <int, int > >[V];
	}

	void addEdge ( int u, int v, int w )
	{
        adj[u].push_back( make_pair( v, w ));
        adj[v].push_back( make_pair( u, w ));

        Edge e { u, v, w };
        edge.push_back ( e );
    }
	int ShortestPath (int u, int v )
    {
        set< pair<int, int> > setds;

        vector<int> dist(V, INF);

        setds.insert(make_pair(0, u));
        dist[u] = 0;

        while (!setds.empty())
        {
            pair<int, int> tmp = *(setds.begin());
            setds.erase(setds.begin());

            int u = tmp.second;

            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight)
                {
                    if (dist[v] != INF)
                        setds.erase(setds.find(make_pair(dist[v], v)));
                    dist[v] = dist[u] + weight;
                    setds.insert(make_pair(dist[v], v));
                }
            }
        }
        return dist[v];
    }

};


///

class cab
{
    int cno;
    int rate;
    int location;
    int status;
public:
    cab()
    {
        cno=rate=status=location=0;
    }
    int getdata()
    {
        cout<<"Enter cab no. : ";
        cin>>cno;
        cout<<endl;
        cout<<"Enter cab price : ";
        cin>>rate;
        cout<<endl;
        cout<<"Enter cab location : ";
        cin>>location;
        cout<<endl;
    }
    int showdata()
    {
        cout<<"  "<<cno<<"    \t\t"<<rate<<"      \t\t"<<location<<"     \t\t\t"<<status<<endl;
    }
    int getloc()
    {
        return location;
    }
    int setloc(int k)
    {
        location=k;
    }
    int getrate()
    {
        return rate;
    }
    int getstat()
    {
        if(status==1)
            return 1;
        else
            return 0;
    }
    int setstat(int k)
    {
        status=k;
    }
    int getcabno(int k)
    {
        if(k==cno)
            return 1;
        else
            return 0;
    }
    int retcabno()
    {
        return cno;
    }
    int freecab()
    {
        status=0;
    }

};

//Customer
class customer
{
    cab *ca;
    int cid;
    string name;
    int iloc;
    int floc;
    int phone;
    int price;
    int cacnt;
    int cabno;
public:
    customer()
    {
        cid=cabno=phone=price=cacnt=0;
        name="abc";
        iloc=floc=0;
    }
    int getdata()
    {
        cout<<"Enter customer no. : ";
        cin>>cid;
        cout<<endl;
        cout<<"Enter customer name : ";
        cin>>name;
        cout<<endl;
        cout<<"Enter customer phone : ";
        cin>>phone;
        cout<<endl;
        cout<<"Enter initial location : ";
        cin>>iloc;
        cout<<endl;
        cout<<"Enter destination : ";
        cin>>floc;
        cout<<endl;
    }
    int getloc()
    {
        cout<<"Enter initial location : ";
        cin>>iloc;
        cout<<endl;
        cout<<"Enter destination : ";
        cin>>floc;
        cout<<endl;
    }
    int getcno(int n)
    {
        if(cid==n)
            return 1;
        else
            return 0;
    }
    int retcno()
    {
        return cid;
    }
    int setcab(cab *a)
    {
        if(a->getstat())
        {
            return 0;
        }
        else
        {
            ca=a;
            ca->setstat(1);
            ++cacnt;
            return 1;
        }
    }
    int getiloc()
    {
        return iloc;
    }
    int getfloc()
    {
        return floc;
    }
    int showdata()
    {
        cout<<"  "<<cid<<"   \t\t"<<name<<"   \t\t"<<phone<<"    \t\t"<<cacnt<<endl;
    }
    int setprice(int n)
    {
        price=ca->getrate()*n;
    }
    int getprice()
    {
        return price;
    }


};



int thank()
{
    cout<<"************************************************************************************************************************\n\n";

    cout<<"*******************************************************THANK  YOU*******************************************************\n\n";

    cout<<"************************************************************************************************************************\n\n";
}
int main()
{
    ///
    int V = 9;
	Graph g(V);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
    ///
    int n,ch=1;
    cout<<"************************************************************************************************************************\n\n";
    cout<<"**************************************************WELCOME TO JSV CABS***************************************************\n\n";
    cout<<"************************************************************************************************************************\n\n";
    cout<<"\t\t\t\t\t\tPRESS ENTER TO CONTINUE....";
    cin.get();
    while(ch)
    {
        system("cls");
        lable:
        cout<<"SELECT AN OPTION: \n";
        cout<<"1. Add a cab\n";
        cout<<"2. New Customer: Book a cab\n";
        cout<<"3. Existing Customer: Book a cab\n";
        cout<<"4. Free a cab\n";
        cout<<"5. View cab list\n";
        cout<<"6. View customer list\n";
        cout<<"7. Exit\n";
        cout<<"CHOICE : ";
        cin>>n;
        switch(n)
        {
            cin.get();
            system("cls");
        case 1:{
            c[cnt]=new cab;
            c[cnt]->getdata();
            cnt++;
            cout<<endl;
            break;}
        case 2:{

            cu[ccnt]=new customer;
            cu[ccnt]->getdata();
            int fl=0;
            cout<<endl;
            int m=cu[ccnt]->getiloc();
            int n=cu[ccnt]->getfloc();
            int l;
            l=g.ShortestPath(m,n);
            int index,cmini=INF;
            for(j=0;j<cnt;j++)
            {
                if(!c[j]->getstat())
                {
                    int y=c[j]->getloc();
                    int d=g.ShortestPath(m,y);
                    if(d<cmini)
                    {
                        cmini=d;
                        index=j;
                        fl=1;
                    }
                }

            }
            if(!fl)
            {
                cout<<"NO CAB AVAILABLE NEARBY\n";
                goto lable;
            }
            if(cu[ccnt]->setcab(c[index]))
            {
                cout<<"Cab No. "<<c[index]->retcabno()<<" will arrive shortly\n";
                cu[ccnt]->setprice(l);
                c[index]->setloc(n);
                cout<<"The total cost for the ride will be "<<cu[ccnt]->getprice()<<endl;
            }
            cout<<endl;
            ccnt++;
            break;}
        case 3:{
            int no;
            cout<<"Enter Customer No.: ";
            cin>>no;
            cout<<endl;
            int fl=0;
            for(i=0;i<ccnt;i++)
            {
                if(cu[i]->getcno(no))
                {
                    cu[i]->getloc();

                    int m=cu[i]->getiloc();
                    int n=cu[i]->getfloc();
                    int l;
                    l=g.ShortestPath(m,n);
                    int index,cmini=INF;
                    for(j=0;j<3;j++)
                    {
                        if(!c[j]->getstat())
                        {

                            int y=c[j]->getloc();
                            int d=g.ShortestPath(m,y);
                            if(d<cmini)
                            {
                                cmini=d;
                                index=j;
                                fl=1;
                            }
                        }
                    }
                    if(!fl)
                    {
                        cout<<"NO CAB AVAILABLE NEARBY\n";
                        goto lable;
                    }
                    if(cu[i]->setcab(c[index]))
                    {
                        cout<<"Cab No. "<<c[index]->retcabno()<<" will arrive shortly\n";
                        cu[i]->setprice(l);
                        c[index]->setloc(n);
                        cout<<"The total cost for the ride will be "<<cu[i]->getprice()<<endl;

                    }
                    cout<<endl;
                }
            }
            break;
            }
        case 4:{
            int nn;
            int flag=0;
            cout<<"Enter cab no.: ";
            cin>>nn;
            for(int i=0;i<cnt;i++)
            {
                if(c[i]->getcabno(nn))
                {
                    c[i]->freecab();
                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }
            if(flag)
                cout<<"CAB FREED\n";
            else
                cout<<"No such cab exists\n";
            break;
        }
        case 5:{
            cout<<"CAB ID\t\tRATE/KM\t\tLOCATION\t\tCAB STATUS\n";
            for(int i=0;i<cnt;i++)
            {
                c[i]->showdata();
            }
            cout<<endl;
            cin.get();
            break;
        }
        case 6:{
            cout<<"CUST ID\t\tNAME\t\tPHONE\t\tCAB COUNT\n";
            for(int i=0;i<ccnt;i++)
            {
                cu[i]->showdata();
            }
            cout<<endl;
            cout<<"\t\t\t\t\tPRESS ENTER TO CONTINUE....\n";
            cin.get();
            break;
        }
        case 7:
            system("cls");
            thank();
            goto end;
            break;
        default:
            cout<<"CHOOSE AGAIN\n";
            break;

        }
        cout<<"WANT TO CONTINUE(0/1)?? : ";
        cin>>ch;
        cout<<endl;
    }
    thank();
    end:
    return 0;

}

