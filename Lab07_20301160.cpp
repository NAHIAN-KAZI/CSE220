#Task1
class KeyIndex:

    def __init__(self,arr):
        self.least=arr[0]
        maximum=arr[0]
        for i in arr:
            if(maximum<i):
                maximum=i
            elif(self.least>i):
                self.least=i
        if(self.least<0):
            self.auxArray=[0]*(maximum+1+self.least*-1)
            for i in arr:
                self.auxArray[i+self.least*-1]+=1
        else:
            self.auxArray=[0]*(maximum+1)
            for i in arr:
                self.auxArray[i]+=1
    def search(self,value):
        if(self.least<0):
            value+=(self.least*-1)
        if(value>len(self.auxArray) or value<0):
            print("Can't find value")
        elif(self.auxArray[value]>0):
            print("Value Found")
        else:
            print("Can't find value")
            
    def sort(self):
        my_list=[]
        for i in range(len(self.auxArray)):
            if(self.auxArray[i]>0):
                while(self.auxArray[i]>0):
                    if(self.least<0):
                        my_list.append(i-(self.least*-1))
                        self.auxArray[i]-=1
                    else:
                        my_list.append(i)
                        self.auxArray[i]-=1
        return my_list        
arr=[1,2,3,4,-7,-8,-11,8,9,10,-26]
Index_arr=KeyIndex(arr)
Index_arr.search(-1)
Index_arr.search(10)
Index_arr.search(-8)
mylist=Index_arr.sort()
print(mylist)

#TASk2 
class hashmap:
    def __init__(self,arr):
        self.hashArr=[None]*len(arr)
        for i in arr:
            con = 0
            digit = 0
            for j in i:
                if(j.isdigit()):
                    digit+=int(j)
                elif ( j !='A' and j !='E' and j !='I' and j !='O' and j !='U'):
                    con+=1
            digit=(digit+(con*24))%len(arr)
            if(self.hashArr[digit]==None):
                self.hashArr[digit]=i
            else:
                while (self.hashArr[digit]!=None):
                    digit+=1
                    if(digit>=len(self.hashArr)):
                        digit%=len(self.hashArr)
                self.hashArr[digit]=i
        print(self.hashArr)
arr=["GHA1","HGS12","UFC2","FTTDTR5","HJGSUF3","NBUF64","HGYG5","SCDWE23B6","QRVS22"]
x=hashmap(arr)