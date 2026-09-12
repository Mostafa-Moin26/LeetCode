// Problem link ----->
https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Solution ---->

class Solution {
public:
    vector<int> getNSE( vector<int>& heights , int n ) {

        stack<int> st ;
        vector<int> NSE(n,0) ;

        for ( int i = n-1 ; i >= 0 ; i-- ) {

            while( !st.empty() && heights[st.top()] >=  heights[i] ) st.pop() ;

            if ( st.empty() ) NSE[i] = n ;

            else NSE[i] = st.top() ;

            st.push(i) ;

        }

        return NSE ;

    }

        vector<int> getPSE( vector<int>& heights , int n ) {

        stack<int> st ;
        vector<int> PSE(n,0) ;

        for ( int i = 0 ; i < n ; i++ ) {

            while( !st.empty() && heights[st.top()] >=  heights[i] ) st.pop() ;

            if ( st.empty() ) PSE[i] = -1 ;

            else PSE[i] = st.top() ;

            st.push(i) ;

        }

        return PSE ;

    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size() ;
        
        vector<int> NSE = getNSE(heights,n) ;
        vector<int> PSE = getPSE(heights,n) ;

        int maxi = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            int length = NSE[i] - PSE[i] - 1 ;
            int area = length * heights[i] ;
            
            maxi = max( maxi , area ) ;

        }

        return maxi;
        
    }
};