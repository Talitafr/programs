function [sol info res err]=diagonal(a,b,exa)
%
% esta função resolve um sistema linear para matrizes diagonais
%  testa algumas condições que impossibilitam a solução do sistema fornecido e
%  devolve a informação se conseguiu realizar ou não a solução e qual a razão
%  caso não tenha conseguido.
%
% parâmetros de entrada:
%  a - matriz dos coeficientes;
%  b - lado direito;
%  exa - solução exata do problema para permitir o cálculo do erro.
%
% parâmetros de saída:
%  sol - a solução encontrada, caso não tenha sido possível resolver, retorna Inf;
%  info - 1 - o sistema foi resolvido e "sol", "res" e "err" têm os valores calculados;
%         2 - a matriz "a" não é quadrada, devolve "sol", "res" e "err" com Inf;
%         3 - o lado direito não têm o mesmo número de linhas da matriz dos coeficientes,
%               devolve "sol", "res" e "err" com Inf;
%         4 - a matriz "a" possui zero em alguma das posições da diagonal principal,
%               devolve "sol", "res" e "err" com Inf;
%  res - retorna a norma resíduo relativo dada pela fórmula norm(a*sol-b);
%  err - retorna a norma erro relativo dada pela fórmula norm(sol-exa).
%
[m n] = size(a);
[o u] = size(b);
if(m!=n)
  sol=Inf;
  res=Inf;
  err=Inf;
  info=2;
  return;
elseif(m!=o)
  sol=Inf;
  res=Inf;
  err=Inf;
  info=3;
else 
    sol=zeros(m);
    for j=1:m
      if(a(j,j)==0)
        info=4;
        res=Inf;
        sol=Inf;
        err=Inf;
        return;
        endif
    endfor
    for i=1:(m-1)
      ai=eye(m);
      ai(i+1:m,i)=-a(i+1:m,i)/a(i,i);
      b=ai*b;
      a=ai*a;
    endfor
    x=zeros(n,1);
  x=b(1:n,1);
  for j=1:m
    if(a(j,j)==0)
      info=4;
      res=Inf;
      sol=Inf;
      err=Inf;
      return;
      endif
  endfor
for i=m:-1:1
  
    if(i==1)
        x(i,1)=x(i,1)/a(1,1);
    else
        x(i,1)=x(i,1)/a(i,i);
        x(i-1:-1:1,1)=x(i-1:-1:1,1)-x(i,1)*a(i-1:-1:1,i);
        
     endif
  endfor    
    sol=x;
    
    info=1;
    err=norm(sol - exa);
    res=norm(a*sol-b);
    return;
  endif    
endfunction