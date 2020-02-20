#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>


using namespace std;


struct object
{
    string name;
    int price,value;
};

void display(struct object o[],int product)
{
    cout<<setw(20)<<"NAME"<<setw(20)<<"Price"<<setw(20)<<"Importance\n";
    for(int i=product-1; i>=0; i--)
    {
        cout<<setw(20)<<o[i].name<<setw(20)<<o[i].price<<setw(20)<<o[i].value<<"\n";
    }
}



void swap(struct object *a, struct object *b)
{
    struct object t = *a;
    *a = *b;
    *b = t;
}

int partitionprice (struct object arr[], int low, int high)
{
    int pivot = arr[high].price;
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].price < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortprice(struct object arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partitionprice(arr, low, high);
        quickSortprice(arr, low, pi - 1);
        quickSortprice(arr, pi + 1, high);
    }
}

int partitionpriority (struct object arr[], int low, int high)
{
    int pivot = arr[high].value;
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].value < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortpriority(struct object arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partitionpriority(arr, low, high);
        quickSortpriority(arr, low, pi - 1);
        quickSortpriority(arr, pi + 1, high);
    }
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

void knapSack(int W, struct object o[], int n)
{
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (o[i-1].price <= w)
                K[i][w] = max(o[i-1].value + K[i-1][w-o[i-1].price],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    int res = K[n][W];

    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        if (res == K[i - 1][w])
            continue;
        else {

            // This item is included.
            cout<<"\n"<<o[i-1].name<<"\n";


            res = res - o[i-1].value;
            w = w - o[i-1].price;
        }
    }
}

void sortt(struct object o[],int product)
{
    int choice;
    cout<<"==================SORTING SECTION===============\n";
    cout<<"1.Sort On Basis Of Amount\n2.Sort On Basis of Importance\n";
    cout<<"Enter Your choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:quickSortprice(o,0,product-1);
                display(o,product);
                break;
        case 2:quickSortpriority(o,0,product-1);
                display(o,product);
                break;

    }


}

void searchh(struct object o[],int product)
{
    string key;
    cout<<"================SEARCHING BLOCK=============\n";
    cout<<"Enter Type of Expense which is to be Searched : ";
    cin>>key;
    for(int i=0;i<product;i++)
    {
        if(((o[i].name).compare(key))==0)
        {
            cout<<setw(20)<<"NAME"<<setw(20)<<"Price"<<setw(20)<<"Importance\n";
            cout<<setw(20)<<o[i].name<<setw(20)<<o[i].price<<setw(20)<<o[i].value<<"\n";
            return;
        }

    }
    cout<<"=============GIVEN EXPENSE NOT FOUND=================\n";


}


int main()
{

    int members,capacity=0,product,choice,space=20;
    cout<<"Enter Total Earning Members : ";
    cin>>members;
    space=space+4*members;
    bool x=true;
    int a[members];
    for(int i=0; i<members; i++)
    {
        cout<<"Enter Salary of Member "<<i+1<<" : ";
        cin>>a[i];
        capacity+=a[i];//capacity
    }
    cout<<"Enter Total Different Expenses For The Month : ";
    cin>>product;
    space=space+12*product;
    struct object o[product];
    for(int i=0; i<product; i++)
    {
        cout<<"Enter Type of Expense : ";
        cin>>o[i].name;
        cout<<"Enter Price of "<<o[i].name<<" : ";
        cin>>o[i].price;//weight
        cout<<"Enter Importance of "<<o[i].name<<" On scale of 10 : ";
        cin>>o[i].value;//value
    }
    display(o,product);

    do
    {
        cout<<"\n\n======================DISPLAY OPTIONS :===========================\n\n";
        cout<<"1.Total Earning\n2.Sorting of Expense\n3.Searching for Expense\n4.Expenses That Could Be Fulfilled\n5.Exit\n";
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Total Earning is : "<<capacity<<"\n";
            break;
        case 2:
            sortt(o,product);
            break;
        case 3:
            searchh(o,product);
            break;
        case 4:
           knapSack(capacity,o, product);
           break;
        default:x=false;
        }

    }
    while(x);
    cout<<"\n\nEfficiency Of Individual Algorithms:-\n\n";
    cout<<"\n\nSorting:-\n";
    cout<<"Algorithm Used : Quick Sort\n";
    cout<<"Time Complexity :-\n";
    cout<<"Best Case : Already Sorted\n";
    cout<<"Average Case :O(nlogn) \n";
    cout<<"Worst Case : Sorted in Descending Order\n\n";
    cout<<"Searching:- \n";
    cout<<"Algorithm Used : Linear Search\n";
    cout<<"Time Complexity :-\n";
    cout<<"Best Case : Key Found At 1st Position \n";
    cout<<"Average Case :O(n) \n";
    cout<<"Worst Case : Key Found At Last Position Or Not Found\n\n";
    cout<<"Main Algorithm\n";
    cout<<"Algorithm Used : Knapsack \n";
    cout<<"Time Complexity :-\n";
    cout<<"Best Case : Sorted According To Priority\n";
    cout<<"Average Case : O(nW) \nwhere n is the number of items and W is the restriction on weight.\n";
    cout<<"Worst Case : Sorted In Opposite Order Of Priority \n";
    cout<<"\n\nFull Program\n\n";
    cout<<"Time Complexity :-\n";
    cout<<"Best Case : Data Given is in Sorted Order According To Priority \n";
    cout<<"Worst Case : Data Given is in Reverse Sorted Order According To Priority\n";
    cout<<"Average Case : O(n(logn+W))\nwhere n is the number of items and W is the restriction on weight.\n";
    cout<<"\nSpace Complexity :"<<space<<" Bytes \n";


    return 0;

}


