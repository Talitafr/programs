% este código realiza 8 testes: 4 para matrizes triangulares superiores
%  e 4 para matrizes diagonais.
%
n=input('');%entrada de teclado 
switch n
  case 1 % teste para matriz inversível
    a=triu(rand(5))+2*eye(5); % monta matriz inversível
    b=rand(5,1); % monta lado direito
    exa=a\b; % calcula solução exata
    resexa=norm(a*exa-b); % calcula resíduo
    [sol info res err]=subsparatras(a,b,exa);
    disp(info)
    %
    % caso diferença entre resíduo
    % calculado na função e o calculado aqui
    % seja pequena
    %
    if(norm(resexa-res)<10^(-10))
        disp(0)
    else
        disp(1)
    endif  
    %
    % caso diferença  entre erro
    % calculado na função e o calculado aqui
    % seja pequena
    %
    if((abs(norm(exa-sol)-err))<10^(-10))
        disp(0)
    else
        disp(1)
    endif     
case 2 % teste para matriz não quadrada
    a=triu(rand(5,6));  %monta matriz não quadrada
    b=rand(5,1);
    exa=Inf;
    [sol info res err]=subsparatras(a,b,exa);
    disp(info)
    if(res==Inf)
        disp(0)
    else
        disp(1)
    endif    
    if(err==Inf)
        disp(0)
    else
        disp(1)
    endif 
case 3 % teste para lado direito não conforme
    a=triu(rand(5));
    b=rand(6,1);
    exa=Inf;
    [sol info res err]=subsparatras(a,b,exa);
    disp(info)
    if(res==Inf)
        disp(0)
    else
        disp(1)
    endif    
    if(err==Inf)
        disp(0)
    else
        disp(1)
    endif
case 4 % teste para matriz com zero na diagonal principal
    a=triu(rand(5))+2*eye(5);
    b=rand(5,1);
    exa=Inf;
    ind=randi(5);
% coloca zero em uma das entradas da diagonal principal    
    a(ind,ind)=0;
    [sol info res err]=subsparatras(a,b,exa);
    disp(info)
    if(res==Inf)
        disp(0)
    else
        disp(1)
    endif    
    if(err==Inf)
        disp(0)
    else
        disp(1)
    endif 

case 5 %teste com matriz diagonal inversível
    a=diag(diag(rand(5)))+2*eye(5);
    b=rand(5,1);
    exa=a\b;
    resexa=norm(a*exa-b);
    [sol info res err]=diagonal(a,b,exa);
    disp(info)
    if(norm(resexa-res)<10^(-10))
        disp(0)
    else
        disp(1)
    endif  
    if((abs(norm(exa-sol)-err))<10^(-10))
        disp(0)
    else
        disp(1)
    endif 

case 6 % teste para matriz não quadrada
    a=[diag(diag(rand(5))) zeros(5,1)];
    b=rand(5,1);
    exa=Inf;
    [sol info res err]=diagonal(a,b,exa);
    disp(info)
    if(res==Inf)
        disp(0)
    else
        disp(1)
    endif    
    if(err==Inf)
        disp(0)
    else
        disp(1)
    endif 

case 7 % teste para lado direito não conforme
    a=diag(diag(rand(5)))+2*eye(5);
    b=rand(6,1);
    exa=Inf;
    [sol info res err]=diagonal(a,b,exa);
    disp(info)
    if(res==Inf)
        disp(0)
    else
        disp(1)
    endif    
    if(err==Inf)
        disp(0)
    else
        disp(1)
    endif
case 8 % teste para matriz com zero na diagonal principal
    a=diag(diag(rand(5)))+2*eye(5);
    b=rand(5,1);
    exa=Inf;
    ind=randi(5);
 % coloca zero em uma das entradas da diagonal principal 
    a(ind,ind)=0;
    [sol info res err]=diagonal(a,b,exa);
    disp(info)
    if(res==Inf)
        disp(0)
    else
        disp(1)
    endif    
    if(err==Inf)
        disp(0)
    else
        disp(1)
    endif 

otherwise   
        disp('opção inválida, escolha números de 1 a 8')
endswitch
