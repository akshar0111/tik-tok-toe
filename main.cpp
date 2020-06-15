#include<iostream>
using namespace std;

int rep[10]={0,2,4,6,8,10,12,14,16,18};
int ppl;
int i=1,j=0,k;
//this
int insert_char(char x){
    int i=0;
    int x1;
    char a;
    a=x;

    switch(a){
        case 'a':
                x1=1;
            break;
        case 'b':
            x1=2;
            break;
        case 'c':
            x1=3;
            break;
        case 'd':
            x1=4;
            break;
        case 'e':
            x1=5;
            break;
        case 'f':
            x1=6;
            break;
        case 'g':
            x1=7;
            break;
        case 'h':
            x1=8;
            break;
        case 'i':
            x1=9;
            break;
        default :
            cout<<" invalid"<<endl;

    }

    if(rep[x1]%2!=0){
        x1=0;
        goto stop;
    }
    rep[x1]++;
    stop:
    return x1;
}

int check_result(char arr[10])
{
//flag variable default**
int p1=0;
//it passes arr for result

//condition 1 [x,x,x] on line 0
    if((arr[1]=='X')&&(arr[2]=='X')&&(arr[3]=='X'))
    {
        p1=1;
    }
//condition 2 [x,x,x] on line 1
    else if((arr[4]=='X')&&(arr[5]=='X')&&(arr[6]=='X'))
    {
        p1=1;
    }
//condition 3 [x,x,x] on line 2
    else if((arr[7]=='X')&&(arr[8]=='X')&&(arr[9]=='X'))
    {
        p1=1;
    }
//condition 4 for vertical 0
    else if((arr[1]=='X')&&(arr[4]=='X')&&(arr[7]=='X'))
    {
        p1=1;
    }
//condition 5 for vertical in column 1
    else if((arr[2]=='X')&&(arr[5]=='X')&&(arr[8]=='X'))
    {
        p1=1;
    }
//condition 6 for vertical in column 2
    else if((arr[3]=='X')&&(arr[6]=='X')&&(arr[9]=='X'))
    {
        p1=1;
    }
//condition diagonal for x
    else if((arr[1]=='X')&&(arr[5]=='X')&&(arr[9]=='X'))
    {
        p1=1;
    }
//condition 8
    else if((arr[3]=='X')&&(arr[5]=='X')&&(arr[7]=='X'))
    {
        p1=1;
    }

//condition for player 2
//condition 1
    else if((arr[1]=='O')&&(arr[2]=='O')&&(arr[3]=='O'))
    {
        p1=3;
    }
//condition 2
    else if((arr[4]=='O')&&(arr[5]=='O')&&(arr[6]=='O'))
    {
        p1=3;
    }
//condition 3
    else if((arr[7]=='O')&&(arr[8]=='O')&&(arr[9]=='O'))
    {
        p1=3;
    }
//condition 4 for vertical
    else if((arr[1]=='O')&&(arr[4]=='O')&&(arr[7]=='O'))
    {
        p1=3;
    }
//condition 5
    else if((arr[2]=='O')&&(arr[5]=='O')&&(arr[8]=='O'))
    {
        p1=3;
    }
//condition 6
    else if((arr[3]=='O')&&(arr[6]=='O')&&(arr[9]=='O'))
    {
        p1=3;
    }
//condition 7 diagonal
    else if((arr[1]=='O')&&(arr[5]=='O')&&(arr[9]=='O'))
    {
                p1=3;
    }
//condition 8 diagonal
    else if((arr[3]=='O')&&(arr[5]=='O')&&(arr[7]=='O'))
    {
        p1=3;
    }

    else
    {
        goto stop;
    }
stop:
return p1;
}


int main()
{
int i=1,j=0,k;
    char arr[10]={'z','a','b','c','d','e','f','g','h','i'};
    char x,y;
    int flag=0;
    label:
    j++;
    //the basic layout of the game
    cout<<"       "<<arr[1]<<" | "<<arr[2]<<" | "<<arr[3]<<endl;
    cout<<"      ___|___|___"<<endl;
    cout<<"       "<<arr[4]<<" | "<<arr[5]<<" | "<<arr[6]<<endl;
    cout<<"      ___|___|___"<<endl;
    cout<<"       "<<arr[7]<<" | "<<arr[8]<<" | "<<arr[9]<<endl;
    cout<<"         |   |   "<<endl<<endl;
     // no. of turns


    if(i>=4){
            //check if the char on the cross or on the side matches
            int pp1 = check_result(arr);
            // will display output
            if(pp1==1){
                cout<<endl;
                cout<<"########  player 1 is winner :)  ##########"<<endl;
                goto stop;
            }
            if(pp1==3){
                cout<<endl;
                cout<<"########  player 2 is winner :) ##########"<<endl;
                goto stop;
            }
            if(j>=10){
                cout<<"######## match draw #########";
                goto stop;
            }
    }

    if(i<2){
        cout<<"########   hey welcome!   ##########"<<endl<<endl;
        cout<<"player no 1 is 'X' "<<endl;
        cout<<"player no 2 is 'o' "<<endl;
        cout<<"#####################################"<<endl<<endl;
    }
    else{
        cout<<endl<<endl;
    }
    if(flag==0){
        cout<<"player no. 1 ::"<<endl;
        cin>>x;
        int x3;
        x3=insert_char(x);

        if(x3==0){
            goto stop;
        }

        arr[x3]='X';
        flag=1;
        i++;
        x=0;
        goto label;
    }
    else if (flag==1){
        cout<<"player no. 2 :: "<<endl;
        cin>>y;
        x=y;
        int x4;
        x4=insert_char(x);

        if(x4==0){
            goto stop;
        }

        arr[x4]='O';
        flag=0;
        goto label;
    }

    else {
       cout<<"enter a valid option :/"<<endl;
       }

    stop:
    return 0;
}
