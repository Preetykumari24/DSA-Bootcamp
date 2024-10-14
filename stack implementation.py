l=[]
size = 5
while True:
    i=int(input('''
        Enter a Number 
        1. push
        2. pop
        3. Display
        4. exit
        
        Enter Your Choice :- '''))
    
    def push():
    
        if  size == len(l)-1:
            print("Stack OverFlow")
            
        else:
            a=int(input("Enter a Number :- "))
            l.append(a)
            print(f"Stack has Successfully Push")

    def pop():

        if len(l) == 0:
            print("Stack UnderFlow")
        else:
            del l[-1]
            print("Stack has Successfully PoP ")

    def display():
        if len(l) == 0:
            print("Stack UnderFlow")
        else:
            print("Stack ",l)
    
    
    if i==1:
        push()
    elif i==2:
        pop()
    elif i==3:
        display()
    elif i==4:
        print("Stack has Exits..")
    else:
        print("Invalid Choice , Please Enter Number Between 1 to 4")
