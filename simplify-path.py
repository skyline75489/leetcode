class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        dirs = path.split('/')
    	result_path = []
    	for d in dirs:
    		if d == '' or d == '.':
    			continue
    		elif d == '..':
    			try:
    				result_path.pop()
    			except IndexError:
    				pass
    		else:
    			result_path.append(d)
    
    	return '/' + '/'.join(result_path)
