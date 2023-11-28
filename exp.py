MOD = 10**9 + 7

quantidade = int(input())

for _ in range(quantidade):
    base, expoente = map(int, input().split())
    resultado = 1

    while expoente > 0:
        if expoente & 1:
            resultado = ((resultado % MOD) * (base % MOD)) % MOD

        base = ((base % MOD) * (base % MOD)) % MOD
        expoente >>= 1

    print(resultado % MOD)
