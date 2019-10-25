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

void fShift(int n, stack<int>* s ){
   
    int index =0;
    for(int i = 0; i<3; i++){
        if(!s[i].empty() && n==s[i].top()) {index=i; s[index].pop(); break;}  // find location of n and pop it.
    }
    if(s[(index+1)%3].empty() || n < s[(index+1)%3].top() ){
        
        s[(index+1)%3].push(n);                                          // shift n to corresponding new stack
    } else {
         s[(index+2)%3].push(n);
    }
    
}


void fStack(int n, stack<int>* s ){
    // Base case: numbers should be greater than 0
    if(n>0){
       
        // Removes the satck above n
        fStack(n-1,s);
      
       // Shifts n to the new stack 
        fShift(n,s);
        
       //showCurrent(s);                            // Remove comment to see each step simulation
       
       // Again place the removed stack above n
        fStack(n-1,s);
        
       
       
    } else return;
   
}





int main(void){
    
     // Declare the stack
    std::stack<int> s[3];
    s[0].push(10);
    s[0].push(9);
    s[0].push(8);
    s[0].push(7);
    s[0].push(6); 
    s[0].push(5);
    s[0].push(4);
    s[0].push(3);
    s[0].push(2);
    s[0].push(1);
    
   // Show original stack
   
    showCurrent(s);
  
 
   // Call the function to shift the entire stack
  
    fStack(10,s);
 
   
   // Display the final satck
  
    showStack(s);
   
  
    
}
   

    




























