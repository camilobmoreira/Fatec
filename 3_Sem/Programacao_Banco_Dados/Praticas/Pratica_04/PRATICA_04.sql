/*
 * Nomes: 
 * Camilo Bustamante Moreira
 * Giuliano Gimenez
 */

---------------------
-- CRIA TABLESPACE --
---------------------

CREATE TABLESPACE  TS_BD_pratica_04
DATAFILE  '/mnt/Data/Google-Drive-bustamantecamilo23/FATEC/3_SEM/Programacao_BD/BDs/ts_bd_pratica_04.dbf' SIZE 1M
AUTOEXTEND ON;

------------------
-- CRIA USUARIO --
------------------

CREATE USER USER_pratica_04
IDENTIFIED BY aluno
DEFAULT TABLESPACE TS_BD_pratica_04
TEMPORARY TABLESPACE TEMP
QUOTA UNLIMITED ON TS_BD_pratica_04;

-----------------
-- PRIVILEGIOS --
-----------------

GRANT DBA TO USER_pratica_04 WITH ADMIN OPTION;

------------------
--- EXERCICIOS ---
------------------

--------------
-- PARTE 1 --
--------------


/* 1. Avalie cada uma das declarações a seguir. Determine quais delas não estão
  corretas e explique por quê.

a. DECLARE v_id NUMBER(4);

b. DECLARE v_x, v_y, v_z VARCHAR2(10); - Não é possível declarar mais de uma 
  variavel em um unica linha.

c. DECLARE v_birthdate DATE NOT NULL;

d. DECLARE v_in_stock BOOLEAN := 1; - Declarações booleanas aceitam apenas 
  valores true, false, null ou uma expressão que retorne um valor BOOLEAN ou null*/
  

/* 2. Em cada uma das seguintes atribuições, determine o tipo de dados da 
  expressão resultante.

a. v_days_to_go := v_due_date - SYSDATE; - Tipo: date

b. v_sender := USER || ': ' || TO_CHAR(v_dept_no); Tipo: varchar2

c. v_sum := 100,000 + 250,000; Tipo: number

d. v_flag := TRUE; Tipo: boolean

e. v_n1 := v_n2 > (2 * v_n3); Tipo:  boolean

f. v_value := NULL; Tipo: qualquer tipo, pois todos aceitam NULL */

/* 3. Crie um bloco anônimo para a saída da frase "My PL/SQL Block Works" 
  na tela. 

G_MESSAGE
-----------------------
My PL/SQL Block Works


Obs: Para realizar esses exercícios consulte o arquivo  PL-SQL - BLOCO ANÔNIMO 
  e  PL-SQL - SELECT em PLSQL.ppt. */

SET SERVEROUTPUT ON 
Declare
Begin
  DBMS_output.put_line('My PL/SQL Block Works');
END;

/* TABLE USADA PARA EXERCÍCIOS 4 - 8 */
CREATE TABLE TESTE (cod NUMBER(4), nome varchar(10)) ;
insert into teste values (1, 'oi');
insert into teste values (2, 'ola');

/* 4. Crie um bloco anônimo utilizando a Instrução  SELECT. */

DECLARE
v_cod NUMBER(4);
v_nome VARCHAR(10);

BEGIN

SELECT cod, nome
INTO v_cod, v_nome
FROM TESTE
WHERE cod = 2;

END;


/* 5. Crie um bloco anônimo utilizando a Instrução INSERT. */

DECLARE

BEGIN
 insert into teste 
  values (3, 'teste');
END;  

/* 6. Crie um bloco anônimo utilizando a Instrução UPDATE. */

DECLARE

BEGIN
  update teste
  set nome = 'alo'
  where cod = 3;
END;

/* 7. Crie um bloco anônimo utilizando a Instrução DELETE. */

DECLARE

BEGIN
  delete 
  from teste
  where cod = 3;
END;

/* 8. Crie um bloco anônimo utilizando as Instruções  COMMIT e ROLLBACK. */

DECLARE

BEGIN
  commit;
END;

DECLARE

BEGIN
  rollback;
END;


--------------
-- PARTE 2 --
--------------

/* 2) Escreva  blocos PL/SQL para: */

/* a. .Dado dois número inteiro positivo n, calcular e imprimir a sua soma. */

SET SERVEROUTPUT ON
ACCEPT p_n1 PROMPT 'Digite um int: '
ACCEPT p_n2 PROMPT 'Digite outro int: '

DECLARE 
  v_n1 number(5) := &p_n1;
  v_n2 number(5) := &p_n2;
BEGIN
  DBMS_output.put_line(v_n1 || ' + ' || v_n2 || ' = ' || (v_n1 + v_n2));
END;


/* b. Faça um programa que solicite um número (inteiro/positivo) e imprima-o. */

SET SERVEROUTPUT ON
ACCEPT p_num PROMPT 'Digite um numero'

DECLARE
  v_num number(5) := &p_num;
BEGIN
  DBMS_output.put_line('O numero digitado foi '  || v_num);
END;

/* c. Dado um número positivo n, imprimir seu quadrado. */

SET SERVEROUTPUT ON
ACCEPT p_num PROMPT 'Digite um numero: '

DECLARE
  v_num number(5) := &p_num;
BEGIN
  DBMS_output.put_line('O quadrado de '  || v_num || ' = ' || (v_num * v_num));
END;

/* d. Faça um programa que solicite o ano em que uma pessoa nasceu e retorne 
  sua idade. */

SET SERVEROUTPUT ON
ACCEPT p_anoNasc PROMPT 'Digite o ano que nasceu: '

DECLARE
  v_anoNasc date := '&p_anoNasc';
BEGIN
  DBMS_output.put_line('Sua idade é '  || (sysdate - v_anoNasc));
END;

/* e. Dado um número inteiro positivo n verificar se é par ou ímpar. 
  Apresente uma mensagem na tela informando o número e o resultado. */

SET SERVEROUTPUT ON
ACCEPT p_num PROMPT 'Digite um numero: '

DECLARE
  v_num number(5) := &p_num;
BEGIN
  IF mod(v_num, 2) = 0 THEN
    DBMS_output.put_line('O numero '  || v_num || ' é par');
  ELSE 
    DBMS_output.put_line('O numero '  || v_num || ' é impar');
  END IF;  
END;

/* f. Dados três números, imprimi-los em ordem crescente. */

SET SERVEROUTPUT ON
ACCEPT p_num1 PROMPT 'Digite um numero: '
ACCEPT p_num2 PROMPT 'Digite um numero: '
ACCEPT p_num3 PROMPT 'Digite um numero: '

DECLARE
  v_num1 number(5) := &p_num1;
  v_num2 number(5) := &p_num2;
  v_num3 number(5) := &p_num3;
  v_output number(5);
BEGIN
SELECT * INTO v_output FROM (
  select v_num1 p union 
  select v_num2 union 
  select v_num3 a order by p asc);
  DBMS_output.put_line(v_output);
END;



/* g.  Calcular a tabuada de um número fornecido pelo usuário multiplicado 
  de 0 a 10. O resultado deverá ser  apresentado da seguinte maneira:  
Número   x   0 =  Resultado.
Número   x   1   = Resultado 
*/

SET SERVEROUTPUT ON
ACCEPT p_num PROMPT 'Digite um numero: '

DECLARE
  v_num number(5) := &p_num;
  l_loops   NUMBER := 10;
BEGIN

  FOR i IN 0 .. l_loops LOOP
    DBMS_output.put_line(v_num || ' x ' || i || ' = ' || (v_num * i));
  END LOOP;

END;

/* h. Crie um bloco PL/SQL por meio do qual o usuário irá digitar a 
  operação desejada e dois valores, ao final deverá ser exibido o resultado 
  da operação.
  Opções disponíveis: 1 – Divisão;  2 – resto da divisão; 3 – adição;  
    4 – multiplicação;                      
 */
 
SET SERVEROUTPUT ON
ACCEPT p_num1 PROMPT 'Digite um numero: ';
ACCEPT p_num2 PROMPT 'Digite um numero: ';
ACCEPT p_op PROMPT 'Digite a operação desejada  1 – Divisão;  
  2 – resto da divisão; 3 – adição;  4 – multiplicação: ';

DECLARE
  v_num1 number(5)  := &p_num1;
  v_num2 number(5)  := &p_num2;
  v_op number(1) := &p_op;
BEGIN

  IF (v_op = 1) THEN
    DBMS_output.put_line(v_num1 / v_num2);
  ELSIF (v_op = 2) THEN
    DBMS_output.put_line(mod(v_num1, v_num2));
  ELSIF (v_op = 3) THEN
    DBMS_output.put_line(v_num1 + v_num2);
  ELSIF (v_op = 4) THEN
    DBMS_output.put_line(v_num1 * v_num2);
  ELSE 
    DBMS_output.put_line('O opção invalida');
  END IF;  

END;
