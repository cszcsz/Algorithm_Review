# 冒泡排序
def BubbleSort(data):
    length = len(data)
    for i in range(length):
        for j in range(length-i-1):
            if data[j]>data[j+1]:
                data[j+1],data[j] = data[j],data[j+1]


# 插入排序
def InsertSort(data):
    length=len(data)
    for i in range(1,length):
        temp=data[i]
        for j in range(i-1,-1,-1):
            if temp>data[j]:
                break
            else:
                data[j+1]=data[j]
        data[j+1]=temp

# 选择排序
def SelectSort(data):
    length=len(data)
    for i in range(length):
        tempMin,index=data[i],i
        for j in range(i+1,length):
            if data[j]<tempMin:
                tempMin=data[j]
                index=j
        data[index]=data[i]
        data[i]=tempMin


if __name__ == "__main__":
    array = [1,3,2,5,9,8,10,7,6,4]
    # BubbleSort(array)
    # InsertSort(array)
    SelectSort(array)
    print(array)
    