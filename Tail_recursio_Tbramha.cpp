/******************************************************************************

                      Tail-recursion for "Tower of Bramha"
    The recursive function moves one element at a time and calls itself again.
    It moves in clock-wise direction and finds the stack, top element of which
    can be placed into its next or next-to-next stack. After this, the function 
    calls  itself passing 'n' as the parameter, which tells the index of stack  
    which was just modified.(So as to avoid shifting of the same element again)

*******************************************************************************/

#include <iostream>
#include<stack>
using namespace std;

void showStack(stack <int> s[]) 
{ 
       for(int i = 0; i<3; i++)
       {
           cout << '\t'<<"Stack"<< i+1;
         while (!s[i].empty()) 
         { 
             cout << '\t' << s[i].top(); 
             s[i].pop(); 
         } 
          cout<<'\n'; 
       } 
       cout<<'\n';
} 

// Used by showCurrent to display stack element
void showSingle(stack <int> s) 
{ 
    {
           
         while (!s.empty()) 
         { 
             cout << '\t' << s.top(); 
             s.pop(); 
         } 
          cout<<'\n'; 
       } 
       
} 

// Use it to see the simulation
void showCurrent(stack <int> s[]){
   
    for(int i = 0; i<3; i++){
        cout << '\t'<<"Stack"<< i+1;
        showSingle(s[i]);
    }
    cout<<'\n';
}




void fStack(int n, stack<int>* s, int start ){
    // Base case: Stack of start index and one more stack should be empty to ensure completion.
    if(s[start].empty()){              
      
      if(s[(start+1)%3].empty()||s[(start+2)%3].empty()){
           
            cout<<"Process completed"<<'\n';
        return;
       }
       
    } 
        
         for(int i = 0; i<3; i++){
             
        if(i!=n && !s[i].empty()){
            
            if(s[(i+1)%3].empty()|| s[i].top()< s[(i+1)%3].top()){  // if element can be transferred to next satck.
                
                s[(i+1)%3].push(s[i].top());
                s[i].pop();
                n = (i+1)%3; 
                break;
            }
            else if (s[(i+2)%3].empty()|| s[i].top()< s[(i+2)%3].top()){    // if element can be transferred to next-to-next satck.
               
                s[(i+2)%3].push(s[i].top());
                s[i].pop();
                n = (i+2)%3; 
                break; 
                
            }
            
        }
    
    }
    
   
     showCurrent(s);
     fStack(n,s,0);
    
}





int main(void){
    
     // Declare the stack
    std::stack<int> s[3];
   /* s[0].push(10);
    s[0].push(9);
    s[0].push(8); 
    s[0].push(7); 
    s[0].push(6); */
    s[0].push(5); 
    s[0].push(4); 
    s[0].push(3); 
    s[0].push(2);
    s[0].push(1);
    
   // Show original stack
   
    showCurrent(s);
  
 
   // Call the function to shift the entire stack
  
    fStack(2,s,0);          // First parameter can be anything other than last parameter
                            // 0 in this case tells that the elements are in 0th stack 
   
   // Display the final satck
  
    showStack(s);
   
  
    
}

    




























