/* 1. Considere Estudo de Caso 1: Modelo lógico – Biblioteca. 
  Qual o comando abaixo irá gerar um produto cartesiano? 

(A) SELECT e.edi_descricao, l.liv_titulo From Editora e, Livro l; */

/* 2. A partir do script (ENADE 2003), assinale a opção que apresenta comando 
  SQL que permite obter uma lista que contenha o nome de cada fornecedor que 
  tenha fornecido alguma peça, o código da peça fornecida, a descrição dessa 
  peça e a quantidade fornecida da referida peça.
  
(D)  SELECT NOME, CODIGO, DESCRICAO, QUANTIDADE 
  FROM PECAS, FORNECEDORES, FORNECIMENTOS 
  WHERE PECAS.CODIGO = FORNECIMENTOS.COD_PECA AND FORNECEDORES.COD_FORN =FORNECIMENTOS.COD_FORN; */

/* 3. Você deve criar uma consulta para listar todas as pessoas e os  telefones 
dessas pessoas. 
Deve listar as pessoas que possuem e as que não possuem telefone.
  
  Analise o seguinte comando:
    SELECT p.pes_nome, t.tel_numero
    FROM    Pessoa P,
                   Telefone T
    WHERE p.pes_cod=t.pes_cod

( D) Do lado da chave primária p.pes_cod
*/


/* 4. Considere o Estudo de Caso 1: Modelo lógico – Biblioteca, em anexo. 
  Qual o comando abaixo lista as editoras que começam com a letra A.
 
 
(C) SELECT e.edi_descricao From Editora e 
       where e.edi_descricao like ‘A%’; */
       
/* 5. Considere o  Estudo de Caso 1: Modelo lógico – Biblioteca.
  Qual o comando a seguir lista o empréstimo (emp_cod) mais antigo.

 (E) select emp_cod 
 from emprestimo
  where emp_data_emprestimo=(select min(emp_data_emprestimo) from emprestimo);*/
 
/* 
6. Considere o Estudo de Caso 1: Modelo lógico – Biblioteca. 
  Qual o comando lista as editoras que tenham livros cadastrados? 
  Analise as seguintes afirmações: 
  
   
I. Select edi_cod,edi_descricao from editora
    where EXISTS (select * from livro l 
     where l.edi_cod= editora.edi_cod);
II. Select edi_cod,edi_descricao from editora
    where EXISTS (select * from livro l) 
III. Select edi_cod,edi_descricao from editora
    where EXISTS (select * from livro l 
     where l.liv_cod= editora.liv_cod);
IV. Select edi_cod,edi_descricao from editora e,livro l 
     where l.edi_cod= e.edi_cod
 
(A) I e II são verdadeiras.
 */
 
/* 7. Considere o Estudo de Caso 2: Modelo lógico – Catálogo de CDs
. Qual o comando a seguir  lista os CDs que têm o preço igual ao menor preço de cada gravadora?

(A) Select cd_codigo, cd_nome, cd_preco_venda from CD where cd_preco_venda  in
    (select min(cd_preco_venda)
    from CD
    group by grav_codigo);
 */
 
/* 8. Considere o Estudo de Caso 2: Modelo lógico – Catálogo de CDs. 
  Qual o comando a seguir  lista os CDs que têm preço inferior a qualquer um 
  dos cds da gravadora com código 10? 
 
(C) Select cd_codigo, cd_nome, cd_preco_venda
 From CD  Where cd_preco_venda < any (
  Select cd_preco_venda
  From CD
  Where grav_codigo=10)   
*/
 
/* 9. Listar os códigos dos exemplares (exe_cod), a descrição (exe_descricao) 
  do empréstimo de código 1.*/

select ex.EXE_COD, ex.EXE_DESCRICAO
  from EXEMPLAR ex 
  inner join ITEM_EMPRESTIMO ie on ie.EXE_COD = ex.EXE_COD
  inner join EMPRESTIMO e on ie.EMP_COD = e.EMP_COD
  where e.EMP_COD = 1;

/* 10.  Exibir a quantidade de exemplares por livro (liv_titulo, quantidade) */

select l.LIV_TITULO, count(l.LIV_TITULO) quantidade
  from LIVRO l
  inner join EXEMPLAR e on l.LIV_COD = e.LIV_COD
  group by (l.LIV_COD, l.LIV_TITULO);

/* 11. (1,0) Listar os livros que possuam mais de 4 exemplares. */

select l.LIV_TITULO, count(l.LIV_TITULO) quantidade
  from LIVRO l
  inner join EXEMPLAR e on l.LIV_COD = e.LIV_COD
  group by (l.LIV_COD, l.LIV_TITULO) having count(*) > 4;

/* 12. Listar os professores (nome e titulação) com seus respectivos telefones.
  OBS: Listar também os professores que não tenham telefone. Realizar duas 
  resoluções uma com a sintaxe ANSI e outra com a sintaxe ORACLE.
*/

select pe.PES_NOME, pr.TITULACAO, t.TEL_DDD, t.TEL_NUMERO
  from PESSOA pe 
  inner join PROFESSOR pr on pr.PES_COD = pe.PES_COD 
  left join TELEFONE t on t.PES_COD = pe.PES_COD;

select pe.PES_NOME, pr.TITULACAO, t.TEL_DDD, t.TEL_NUMERO
  from PESSOA pe, PROFESSOR pr, TELEFONE t
  where pr.PES_COD = pe.PES_COD and t.PES_COD = pe.PES_COD (+);

/* 13. Exibir o nome da pessoa que mais emprestou livro na biblioteca. */

select p.PES_NOME, p.PES_COD
  from PESSOA p
  where p.PES_COD in 
    (select max(count(e.PES_COD)) 
    from EMPRESTIMO e 
    group by (e.PES_COD));
    
/* 14. Exibir os nomes das pessoas que devolveram livros em atraso. */

select p.PES_NOME
  from PESSOA p
  inner join EMPRESTIMO e on p.PES_COD = e.PES_COD
  inner join DEVOLUCAO d on e.EMP_COD = d.EMP_COD
  where d.DATA_DEV > e.EMP_DATA_PREVDEV;

/* 15. Crie uma view chamada View_Emprestimo que possibilite a consulta dos 
  códigos dos exemplares (exe_cod) dos empréstimos da pessoa de código 1 */
  
  create view view_emprestimo (exe_cod) as 
    select ie.exe_cod
    from emprestimo e
    inner join item_emprestimo ie on ie.emp_cod = e.emp_cod
    inner join pessoa p on p.pes_cod = e.pes_cod
    where p.pes_cod = 1
    with read only;

/* 16. Crie uma sequência denominada edi_cod e insira uma linha na tabela 
  editora utilizando essa sequência no campo edi_cod. 
  (obs: A sequência edi_cod deve começar a partir do último código da 
  editora cadastrado). */

  create sequence edi_cod start with 3;
  
  insert into editora (edi_cod,edi_descricao) values (edi_cod.nextval,'Olá');
