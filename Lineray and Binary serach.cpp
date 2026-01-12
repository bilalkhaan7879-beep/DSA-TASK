#include<iostream>
using namespace std;
int linearsearch(int arr[],int n,int key)
{
    for(int i=0; i<n; i++)
    {
            if(arr[i]==key)
            return i;
            }
            return -1;
            }
            int binarysearch(int arr[],int n,int key)
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
                                int main()
                                {
                                    int n;
                                    cout<<"Enter Number of students:";
                                    cin>>n;
                                    int rollno[n];
                                    cout<<"Enter Roll number:";
                                    for(int i=0;i<n;i++)
                                    cin>>rollno[i];
                                    int key;
                                    cout<<"Enter Roll Number to Search:"<<endl;
                                    cin>>key;
                                    char choice;
                                    cout<<"is the array is sorted?If sorted then press 'Y',;y:";
                                    cin>>choice;
                                    int position;
                                    if(choice=='y' || choice=='Y')
                                    {
                                                   position=binarysearch(rollno,n,key);
                                                   }
                                                   else{
                                                        position=linearsearch(rollno,n,key);
                                                        }
                                                        if(position!=-1)
                                                        cout<<"Roll Nnumber found at position:"<<position+1<<endl;
                                                        else
                                                        cout<<"Roll number not found"<<endl;
                                                        return 0;
                                                        }
                                    
                                    
