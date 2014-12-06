class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        l = len(s)
    	if l == 0:
    		return True
    
    	start = 0
    	end = l-1
    	while start <= end:
    		if not s[start].isalnum():
    		 	start += 1
    		 	continue
    		if not s[end].isalnum():
    			end -= 1
    			continue
    
    		ts = s[start]
    		te = s[end]
    		if s[start].isupper():
    			ts = s[start].lower()
    		if s[end].isupper():
    			te = s[end].lower()
    
    		if ts != te:
    			return False
    		start += 1
    		end -= 1
    
    	return True