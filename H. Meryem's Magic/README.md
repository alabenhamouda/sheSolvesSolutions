# Meriem's Magic:

## idea

the problem consists of finding k primes such that their sum equals n
where 2<=k<=1000 and 4<=N<=2500 and by using the goldbach's conjecture.

### Case 1: **n is even**

we can substract k-2 twos from it and then we look for two
primes that sum to n-(k-2)\*2 (which is an even number).
if n-(k-2)\*2<4 then we print impossible
for example for n=70 and k=7
n=2+2+2+2+2+7+53
for n=1000 and k=501 we print impossible

### Case 2: **n is odd and k>=3**

we substract 3 from n now n-3 is even
and now we look for k-1 primes that sum to n-3 with the same steps from case 1

### Case 3: **n is odd and k=2**

n=p1+p2 where p1 and p2 are primes and their
sum now is odd. this can only happen when one of them is even
and the only even prime is 2 so we have to verify if n-2 is prime
if yes then p1=2 p2=n-2



