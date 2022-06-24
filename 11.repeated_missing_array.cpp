vector<int> Solution::repeatedNumber(const vector<int> &A) {
    //first find dupplicate
    long int n=A.size();
    long int a,b,sum=0,square_sum=0;//a=repeated,b=missing
    for(auto it:A)
    {
        sum +=long(it);//long used for storing big number in sum
        square_sum +=long(it)*long(it);//long used for storing big number
    }
    long int a_b=sum-(long(n)*long(n+1))/2;//long used for storing big number
    long int a2_b2=square_sum-(long(n)*long(n+1)*long(2*n+1))/6;//long used for storing big number
    //calculations;
    long int a_sum_b=a2_b2/a_b;
    a=(a_b+a_sum_b)/2;
    b=(a_sum_b-a_b)/2;
    
    return {a,b};
}
