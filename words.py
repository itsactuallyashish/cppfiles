singles = "Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Eleven,Twelve,Thirteen,Fourteen,Fifteen,Sixteen,Seventeen,Eighteen,Nineteen"
tens = "Twenty,Thirty,Forty,Fifty,Sixty,Seventy,Eighty,Ninety"
denominations = "Hundred,Thousand,Million,Billion,Trillion"

def spell(n: int) -> str:
    
    result = []
    
    sns = singles.split(',')
    tns = tens.split(',')
    dns = denominations.split(',')
    
    if n == 0: return sns[0]
    
    d = 0
    while n > 0:
        
        # work in triads e.g. 1,000,000,...
        nnn = n % 1000
        n = n // 1000
        
        # add a denominator
        if d > 0 and nnn > 0: result += [dns[d]]
        d += 1
        
        # singles and tens
        nn = nnn % 100
        if nn > 0 and nn < 20: result += [sns[nn]]
        if nn > 19 and nn % 10 != 0: result += [sns[nn % 10]]
        if nn > 19: result += [tns[nn // 10 - 2]]
        
        # hundreds
        nn = nnn // 100
        if nn > 0: result += [dns[0], sns[nn]]
        
    return " ".join(result[::-1])

for _ in range(int(input())):
    n = int(input())
    print(spell(n))