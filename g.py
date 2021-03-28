def rotate(A,B,C):
  return (B[0]-A[0])*(C[1]-B[1])-(B[1]-A[1])*(C[0]-B[0])

def grahamscan(A, n):
    P = list(range(n)) # список номеров точек

    for i in range(1,n):
        if A[P[i]][0]<A[P[0]][0]: # если P[i]-ая точка лежит левее P[0]-ой точки
            P[i], P[0] = P[0], P[i] # меняем местами номера этих точек

    for i in range(2,n): # сортировка вставкой
        j = i
        while j>1 and (rotate(A[P[0]],A[P[j-1]],A[P[j]])<0): 
            P[j], P[j-1] = P[j-1], P[j]
            j -= 1
    
    S = [P[0],P[1]] # создаем стек

    for i in range(2,n):
        while rotate(A[S[-2]],A[S[-1]],A[P[i]])<0:
            del S[-1] # pop(S)
        S.append(P[i]) # push(S,P[i])
    return S

if __name__ == '__main__':
    
    fo = open('input.txt', 'r')
    a = fo.read().rstrip().split(' ')
    n = int(a[0])
    A = []
    i = 1
    while i < 2*n:
        A.append([int(a[i]),int(a[i+1])])
        i += 2
    
    S = grahamscan(A, n)
    for i in S:
        print(A[i])