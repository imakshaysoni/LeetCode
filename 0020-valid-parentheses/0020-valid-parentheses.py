class Solution:
    def isValid(self, s: str) -> bool:
        list_1= []
        map = { 
            '{':'}', 
            '(':')',
            '[':']'
        }
        for x in s:
            # if x in (')','}',']'):
            #     return False
            if x in map.keys():
                list_1.append(map[x])
                # print(list_1)
            elif x not in map.keys(): # CLose bracker
                if(len(list_1)==0): return False
                if x != list_1[-1]:
                    return False
                list_1.pop()
        print(list_1)
        if len(list_1) > 0:
            return False 
        return True

    
        