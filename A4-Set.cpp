/*
To create ADT that implement the "set" concept.
a. Add (newElement) -Place a value into the set
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator used to loop
over collection
e. Intersection of two sets
f. Union of two sets
g. Difference between two sets
h.Subset
*/
#include<iostream>
#define MAX 10
using namespace std;

class setc
{
    int num, ele, seta[MAX], flag[MAX];
    public:
    int counter=0;
    setc()
    {
        for(int i=0;i<MAX;i++)
        {
            flag[i]=0;
        }
        cout<<"How many elements do you want to add?"<<endl;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            label:
            cout<<"Enter element "<<i+1<<" :"<<endl;
            cin>>ele;
            for(int j=0;j<i;j++)
            {
                if(seta[j]==ele)
                {
                    cout<<"Element is already present."<<endl;
                    goto label;
                }
            }
            seta[i]=ele;
            flag[i]=1;
            counter++;
        }
    }

    void insert(int ele)
    {
        for(int i=0;i<counter;i++)
        {
            if(seta[i]==ele)
            {
                cout<<"Element is already present."<<endl;
                return;
            }
        }
        seta[counter]=ele;
        flag[counter]=1;
        counter++;
    }

    void remove(int ele)
    {
        int flg=0,k=0;
        for(int i=0;i<counter;i++)
        {
            if(ele==seta[i])
            {
                flg=1;
                k=i;
                break;
            }
        }
        if(flg==0)
        {
            cout<<"Element not present."<<endl;
        }
        else
        {
            flag[k]=0;
        }
    }

    bool contains(int ele)
    {
        for(int i=0;i<counter;i++)
        {
            if(seta[i]==ele)
            {
                return true;
            }
        }
        return false;
    }

    int size()
    {
        int count=0;
        for(int i=0;i<counter;i++)
        {
            if(flag[i]==1)
            {
                count++;
            }
        }
        return count;
    }

    void uni(setc s1, setc s2)
    {
        int setu[2*MAX], flagu[2*MAX], count=0;
        for(int i=0;i<MAX;i++)
        {
            flagu[i]=0;
        }
        for(int i=0;i<s1.counter;i++)
        {
            setu[count]=s1.seta[i];
            flagu[count]=1;
            count++;
        }
        for(int i=0;i<s2.counter;i++)
        {
            int k=0;
            for(int j=0;j<s1.counter;j++)
            {
                if(s2.seta[i]==s1.seta[j])
                {
                    k=1;
                    break;
                }
            }
            if(k==0)
            {
                setu[count]=s2.seta[i];
                flagu[count]=1;
                count++;
            }
        }
        cout<<"A union B is :"<<endl;
        for(int i=0;i<count;i++)
        {
            if(flagu[i]==1)
            {
                cout<<setu[i]<<" ";
            }
        }
        cout<<endl;
    }

    void intersec(setc s1, setc s2)
    {
        int setin[MAX], flagin[MAX], count=0;
        for(int i=0;i<MAX;i++)
        {
            flagin[i]=0;
        }
        for(int i=0;i<s1.counter;i++)
        {
            int k=0;
            for(int j=0;j<s2.counter;j++)
            {
                if(s1.seta[i]==s2.seta[j])
                {
                    k=1;
                    break;
                }
            }
            if(k==1)
            {
                setin[count]=s1.seta[i];
                flagin[count]=1;
                count++;
            }
        }
        cout<<"A intersection B is :"<<endl;
        for(int i=0;i<count;i++)
        {
            if(flagin[i]==1)
            {
                cout<<setin[i]<<" ";
            }
        }
        cout<<endl;
    }

    void diff(setc s1, setc s2)
    {
        int setd[MAX], flagd[MAX], count=0;
        for(int i=0;i<MAX;i++)
        {
            flagd[i]=0;
        }
        for(int i=0;i<s1.counter;i++)
        {
            int k=0;
            for(int j=0;j<s2.counter;j++)
            {
                if(s1.seta[i]==s2.seta[j])
                {
                    k=1;
                    break;
                }
            }
            if(k==0)
            {
                setd[count]=s1.seta[i];
                flagd[count]=1;
                count++;
            }
        }
        cout<<"Difference is :"<<endl;
        for(int i=0;i<count;i++)
        {
            if(flagd[i]==1)
            {
                cout<<setd[i]<<" ";
            }
        }
        cout<<endl;
    }

    void subseta(setc s1, setc s2)
    {
    int cnt = 0;
    for (int i = 0; i < s2.counter; i++)
    {
        int k = 0;
        for (int j = 0; j < s1.counter; j++)
        {
            if (s2.seta[i] == s1.seta[j])
            {
                k = 1;
                break;
            }
        }
        if (k == 1)
        {
            cnt++;
        }
    }
    if (cnt == s2.counter)
    {
        cout << "It is a subset." << endl;
    }
    else
    {
        cout << "It is not a subset." << endl;
    }
    }

    void display()
    {
        for(int i=0;i<counter;i++)
        {
            if(flag[i]==1)
            {
                cout<<seta[i]<<" ";
            }
        }
        cout<<endl;
    }
};

int main()
{
    int ch,ch2,ele;
    cout<<"Creating Set A :"<<endl;
    setc s1;
    cout<<"Creating Set B :"<<endl;
    setc s2;
    do
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"1.Operations on Set A"<<endl;
        cout<<"2.Operations on Set B"<<endl;
        cout<<"3.Union"<<endl;
        cout<<"4.Intersection"<<endl;
        cout<<"5.A-B"<<endl;
        cout<<"6.B-A"<<endl;
        cout<<"7.Is A Subset B?"<<endl;
        cout<<"8.Is B Subset A?"<<endl;
        cout<<"9.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                do
                {   
                cout<<"Operation on Set A"<<endl;
                cout<<"Select Operation:"<<endl;
                cout<<"1.Insert element"<<endl;
                cout<<"2.Remove element"<<endl;
                cout<<"3.Counter Of Set"<<endl;
                cout<<"4.Count elements"<<endl;
                cout<<"5.Check for element"<<endl;
                cout<<"6.Display Set"<<endl;
                cout<<"7.Back"<<endl;
                cin>>ch2;
                switch (ch2)
                {
                case 1:
                    cout<<"Enter element to add :"<<endl;
                    cin>>ele;
                    s1.insert(ele);
                    break;
                case 2:
                    cout<<"Enter element to remove :"<<endl;
                    cin>>ele;
                    s1.remove(ele);
                    break;
                case 3:
                    cout<<"Counter is at "<<s1.counter<<" index"<<endl;
                    break;
                case 4:
                    cout<<"Set contains "<<s1.size()<<" elements"<<endl;
                    break;
                case 5:
                    cout<<"Enter element to check:"<<endl;
                    cin>>ele;
                    s1.contains(ele);
                    break;
                case 6:
                    s1.display();
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
                }
                }while(ch!=7);
                break;
            case 2:
                do
                {
                cout<<"Operation on Set B"<<endl;
                cout<<"Select Operation:"<<endl;
                cout<<"1.Insert element"<<endl;
                cout<<"2.Remove element"<<endl;
                cout<<"3.Counter Of Set"<<endl;
                cout<<"4.Count elements"<<endl;
                cout<<"5.Check for element"<<endl;
                cout<<"6.Display Set"<<endl;
                cout<<"7.Back"<<endl;
                cin>>ch2;
                switch (ch2)
                {
                case 1:
                    cout<<"Enter element to add :"<<endl;
                    cin>>ele;
                    s2.insert(ele);
                    break;
                case 2:
                    cout<<"Enter element to remove :"<<endl;
                    cin>>ele;
                    s2.remove(ele);
                    break;
                case 3:
                    cout<<"Counter is at "<<s2.counter<<" index"<<endl;
                    break;
                case 4:
                    cout<<"Set contains "<<s2.size()<<" elements"<<endl;
                    break;
                case 5:
                    cout<<"Enter element to check:"<<endl;
                    cin>>ele;
                    s2.contains(ele);
                    break;
                case 6:
                    s2.display();
                    break;
                default:
                    cout<<"Invalid Error"<<endl;
                    break;
                }
                }while(ch!=7);
                break;
            case 3:
                s1.uni(s1, s2);
                break;
            case 4:
                s1.intersec(s1, s2);
                break;
            case 5:
                s1.diff(s1, s2);
                break;
            case 6:
                s1.diff(s2, s1);
                break;
            case 7:
                s1.subseta(s1,s2);
                break;
            case 8:
                s1.subseta(s2,s1);
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;
        }
    }while(ch!=9);
    
    return 0;
}
