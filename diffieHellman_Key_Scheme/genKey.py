import time
st=time.time()
g=13
n=9999
n1=2432
n2=9023
gn1=(g**n1)%n
gn2=(g**n2)%n
gn1n2=(gn1**n2)%n
gn2n1=(gn2**n1)%n
print("gn1n2 : ",gn1n2)
print("gn2n1 : ",gn2n1)
file=open("privateKey.txt","w")
file.write(str(gn1n2))
file.close()
ft=time.time()
print(ft-st)
