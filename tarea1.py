"""
Federico Terán Pascuas
Código: 8977473
"""
################ Punto 1 ################
def verificarDiagonales(mat):
    ans = True
    i = 0
    while i < len(mat) and ans:
        if mat[i][i] != mat[i][len(mat) - 1 - i]:
            ans = False
        i += 1
    return ans

################ Punto 2 ################
def esCapicua(l):
    ans = True
    i = 0
    while i < len(l) / 2 and ans:
        if l[i] != l[len(l) - 1 - i]: 
            ans = False
        i += 1
    return ans

################ Punto 3 ################
#a)
def diferenciaListas(listaA, listaB):
    for i in range(len(listaB)):
        if listaB[i] in listaA: listaA.remove(listaB[i])
    return listaA

#b)
def leerimprimir():
    cases = int(input())
    for i in range(cases):
        listaA = [int(a) for a in input().split()]
        listaB = [int(a) for a in input().split()]

        listaA.pop(0)
        listaB.pop(0)

        ans = diferenciaListas(listaA,listaB)
        for j in range(len(ans)):
            if j < len(ans) - 1:
                print("%d, " % (ans[j]),end="")
            else:
                print("%d" % (ans[j]))

################ Punto 4 ################
def mostrarPrimos(n):
    ans = []
    sumDigitos = []
    for i in range (2,n):
        j, flag = 2, True
        while j <= i // 2 and flag:
            if i % j == 0:
                flag = False
            j += 1
        if flag: 
            ans.append(str(i))
            suma = 0
            num = i
            while num != 0:
                suma += num % 10
                num //= 10
            if str(suma) in ans: sumDigitos.append(str(i))
    print("Números primos entre 1 y %d:" % (n))
    print("--> %s" % (",\n--> ".join(ans)),end="")
    print("\n")
    print("Números entre 1 y %d con suma de dígitos con valor primo:" % (n))
    print(", ".join(sumDigitos))   

################ Punto 5 ################
def sumarValoresMatriz(disp,par):
    ans = 0
    for i in range(len(par)):
        if par[i][0] in disp:
            for j in range(len(disp[par[i][0]])):
                if par[i][1] == disp[par[i][0]][j][0]:
                    ans += disp[par[i][0]][j][1]
    return ans