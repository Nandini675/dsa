class Solution {
public:
    string largestOddNumber(string num) {
     int n= num.size();

     int s=n-1;
      if((num[s]%2)==1) return num;
  
     while(s>=0)   {
        
        if(num[s]%2==1)
        break;
            s--;

        }

    return num.substr(0,s+1);
    


     }
    
};