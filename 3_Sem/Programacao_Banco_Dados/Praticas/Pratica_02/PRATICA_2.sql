/* 01 - Quais as gravadoras que não possuem CDs cadastrados com preço inferior 
  a 80,00? */

select grav_codigo, grav_nome 
  from gravadora 
  where grav_codigo not in (  
    select grav_codigo 
    from cd 
    where cd_preco_venda < 80);

/* 02 - Quais os CDs que têm o preço igual ao maior preço de cada gravadora? */

select CD_CODIGO, CD_NOME 
  from CD 
  where CD_PRECO_VENDA in (
    select max(CD_PRECO_VENDA) 
    from CD group by GRAV_CODIGO);

/* 03 - Quais os CDs que têm preço inferior a qualquer outro CD da gravadora 
  com código 10? */

select CD_CODIGO, CD_NOME 
  from CD 
  where CD_PRECO_VENDA < (
    select CD_PRECO_VENDA 
    from CD where GRAV_CODIGO = 10);

/* 04 - Quais CDs têm o preço de venda menor que a média de preço de venda 
  de todas as gravadoras? */

select CD_CODIGO, CD_NOME 
  from CD 
  where CD_PRECO_VENDA < all (
    select avg(CD_PRECO_VENDA)
    from CD group by GRAV_CODIGO);

/* 05 - Liste os nomes dos CDs que tenham preço de venda maior que 10,00 reais 
  ou a gravadora seja a de código 3, ordenados por ordem alfabética 
  decrescente dos nomes dos CDs. Exibir os nomes dos CDs em iniciando com a 
  letra maiúscula. */

select initcap(CD_NOME), CD_PRECO_VENDA, GRAV_CODIGO
  from cd
  where CD_PRECO_VENDA > 10 OR GRAV_CODIGO = 3
  order by CD_NOME desc;


/* 06 - Exibir o nome, a data de lançamento e nome da gravadora dos CDs 
  que possuem data de lançamento em um intervalo de datas.  */

select c.CD_NOME, c.CD_DATA_LANCAMENTO, g.GRAV_NOME
  from CD c 
  inner join gravadora g on c.GRAV_CODIGO = g.GRAV_CODIGO
  where c.CD_DATA_LANCAMENTO between '01/03/17' and '17/03/17';
  
/* 07 - Exibir o nome do Cd e de suas gravadoras, exiba também os CD´S que 
  não possuam gravadoras. */

select c.CD_NOME, g.GRAV_NOME
  from CD c 
  left join gravadora g on c.GRAV_CODIGO = g.GRAV_CODIGO;

/* 08 - Listar quantas músicas que há em cada CD. (Exibir código do CD e a 
  quantidade de música). */

select c.CD_CODIGO, count(f.FAIXA_NUMERO) as QTD_MUSICA
  from cd c 
  inner join faixa f on f.CD_CODIGO = c.CD_CODIGO
  group by (c.CD_CODIGO);

/* 09 - Definir a qual categoria (cat_codigo) cada Cd pertence. */

select c.CD_CODIGO, cat.cat_codigo
  from cd c, CD_CATEGORIA cat 
  where cd.CD_PRECO_VENDA between cat.MENOR_PRECO and cat.MAIOR_PRECO;

/* 10 - Listar o nome do CD indicado para cada CD gravado. */

select t1.cd_nome as cd_gravado, t2.cd_nome as cd_indicado
  from cd t1 
  inner join cd t2 on t1.CD_INDICADO = t2.CD_CODIGO;
  
/* 11 - Imagine que você realizou cada um dos comandos abaixo no Oracle, 
  sem o comando Commit Automático selecionado. Após realizar o comando 
  Select * from CD_Categoria qual será o resultado, desenhe a tabela com 
  os dados. 

    CAT_CODIGO  | MENOR_PRECO | MAIOR_PRECO
        7	      |	  52.00  		|	  60.00
*/

/* 12 - Liste o código, nome, preço de venda, o tempo de duração total, o 
  nome da gravadora do CD de código 101. */
  
select c.CD_CODIGO, c.CD_NOME, c.CD_PRECO_VENDA, 
    sum(m.MUS_DURACAO) duracao_total, g.GRAV_NOME
  from cd c 
  inner join gravadora g on g.GRAV_CODIGO = c.GRAV_CODIGO
  inner join faixa f on f.CD_CODIGO = c.CD_CODIGO 
  inner join musica m on m.MUS_CODIGO = f.MUS_CODIGO
  where c.CD_CODIGO = 101
  group by (c.CD_CODIGO, c.CD_NOME, c.CD_PRECO_VENDA, g.GRAV_NOME);

/* 13 - Listar o nome das gravadoras que possuem mais de 2 Cds relacionados 
  a ela. */
  
select g.GRAV_NOME, count(c.CD_CODIGO) QTDE_CDS
  from gravadora g
  inner join cd c on c.GRAV_CODIGO = g.GRAV_CODIGO
  group by (c.CD_CODIGO, g.GRAV_NOME)
  having count(*) > 2;
  

/* 14 - Listar o nome da música de maior duração. */

select MUS_NOME
  from musica 
  where MUS_DURACAO = (
    select max(MUS_DURACAO) 
    from musica);  
  

/* 15 - Listar o nome das músicas, a faixa e o nome do CD em que está a música, 
  apenas os Cds de código 102 e 103. */
  
select m.mus_nome, f.faixa_numero, c.cd_nome
  from musica m 
  inner join faixa f on m.MUS_CODIGO = f.MUS_CODIGO
  inner join cd c on f.CD_CODIGO = c.CD_CODIGO
  where c.CD_CODIGO = 102 or c.CD_CODIGO = 103;


/* 16- Listar (um único resultado) os autores (código autor, nome autor) 
  com código menor que 10 e as musicas (código musica, nome musica) com 
  código menor que 15. (Utilizarem UNION). */

select a.AUT_CODIGO, a.AUT_NOME
  from autor a 
  where a.AUT_CODIGO < 10
  union
  select m.MUS_CODIGO, m.MUS_NOME
  from musica m
  where m.MUS_CODIGO < 15;