#include<iostream>
#include<algorithm>
using namespace std;
int binarysearchAsc(int arr[],int n,int key)
{
    int low=0,high=n-1;
    while(low<=high)
    {
                    int mid=(low+high)/2;
                    if(arr[mid]==key)
                    return mid;
                    else if(arr[mid]<key)
                    low=mid+1;
                    else
                    high=mid-1;
                    }
                    return -1;
                    }
                    
                    int binarysearchDsc(int arr[],int n,int key)
                    {
					
                    int low= 0, high= n-1;
                    while(low<=high) {
					
                    
                                    int mid=(low=high)/2;
                                    if(arr[mid]==key)
                                    return mid;
                                    else if(arr[mid]>key)
                                    low=mid+1;
                                    else
                                    high=mid-1;
                                    }
                                    return -1;
                                    }
                                    
                                    
                                    
                                    int main()
                                    {
                                        int n;
                                        cout<<"Enter number of Students:";
                                        cin>>n;
                                        int rollno[n];
                                        cout<<"Enter Roll Number of studnets:";
                                        for(int i=0;i<n;i++)
                                        cin>>rollno[i];
                                        int key;
                                        cout<<"Enter Roll Number to Search:";
                                        cin>>key;
                                        int position;
                                        if(key%2==0)
                                        {
                                                    sort(rollno,rollno+n);
                                                    cout<<"Performing Binary Serach (Ascending Order):"<<endl;
                                                    position=binarysearchAsc(rollno,n,key);
                                                    }
                                                    else {
                                                         sort(rollno,rollno+n);
                                                         cout<<"Performing Binary search (Desending Order):"<<endl;
                                                         position=binarysearchDsc(rollno,n,key);
                                                         }
                                                         if(position!=-1)
                                                         cout<<"Roll Number Found at a Position:"<<position+1<<endl;
                                                         else
                                                         cout<<"Roll Number Not Found!!"<<endl;
                                                         return 0;
                                                         }
                                                          
                                        
                                                         
                                                         
                                                    
                                                    
