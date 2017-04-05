--01. Listar todos os clientes.
SELECT * FROM CLIENTE;

--02. Listar todos os pedidos ordenados por data.
SELECT * FROM PEDIDO ORDER BY PED_DATA;

--03. Listar todos os produtos.
SELECT * FROM PRODUTO;

--04. Listar o nome do cliente, o nome do vendedor do pedido de código 2.  
SELECT C.CLI_NOME, V.VEN_NOME FROM CLIENTE C 
  INNER JOIN PEDIDO P ON P.CLI_CODIGO = C.CLI_CODIGO 
  INNER JOIN VENDEDOR V ON V.VEN_CODIGO = P.VEN_CODIGO
  WHERE P.PED_NUMERO = 2;

--05.  Listar a quantidade de pedidos.
SELECT COUNT (*) FROM PEDIDO;

--06. Listar a quantidade de pedido que cada vendedor realizou (Dica: Utilizar group by)
SELECT VEN_CODIGO, COUNT (*) QTDE_PEDIDOS  FROM PEDIDO GROUP BY VEN_CODIGO;

--07. Listar a quantidade de pedido que cada vendedor realizou (Dica: Utilizar group by) Exibir o nome do vendedor e quantidade.
SELECT P.VEN_CODIGO, V.VEN_NOME, COUNT (*) QTDE_PEDIDOS  FROM PEDIDO P
  INNER JOIN VENDEDOR V ON V.VEN_CODIGO = P.VEN_CODIGO 
  GROUP BY P.VEN_CODIGO, V.VEN_NOME;

--08. Listar todos os itens do pedido de código 1.
SELECT PRO_CODIGO, PED_NUMERO FROM ITEM_DO_PEDIDO WHERE PED_NUMERO = 1;

--09. Listar todos os itens (Nome do Produto) do pedido de código 1.
SELECT P.PRO_CODIGO, P.PROD_DESCRICAO, IP.PED_NUMERO FROM PRODUTO P
  INNER JOIN ITEM_DO_PEDIDO IP ON P.PRO_CODIGO = IP.PRO_CODIGO 
  WHERE IP.PED_NUMERO = 1;

--10. Listar a soma total do pedido de código 1.
SELECT SUM(P.PRO_VALOR_UNIDADE * IP.ITEM_QUANTIDADE) TOTAL, IP.PED_NUMERO FROM PRODUTO P
  INNER JOIN ITEM_DO_PEDIDO IP ON P.PRO_CODIGO = IP.PRO_CODIGO 
  WHERE IP.PED_NUMERO = 1 GROUP BY IP.PED_NUMERO;

--11. Listar os clientes e os seus telefones (Listar apenas os clientes que possuam telefone).
SELECT C.CLI_NOME, T.TEL_NUMERO FROM CLIENTE C
  INNER JOIN TELEFONE T ON T.CLI_CODIGO = C.CLI_CODIGO;

--12. Listar os clientes e os seus telefones (Listar também os clientes que não possuam telefone).
SELECT C.CLI_NOME, T.TEL_NUMERO FROM CLIENTE C
  LEFT OUTER JOIN TELEFONE T ON T.CLI_CODIGO = C.CLI_CODIGO;

--13. Listar todos os pedidos realizados na data 01/10/2010.
SELECT * FROM PEDIDO WHERE PED_DATA = '01/10/2010';

--14. Listar todos os pedidos realizados na data 01/10/2010 e que possuem prazo de entrega maior que 3.
SELECT * FROM PEDIDO WHERE PED_DATA = '01/10/2010' AND PED_PRAZO_ENTREGA > 3;

--15. Listar todas as vendas(pedidos) do produto Queijo.
SELECT PED.PED_NUMERO, PRO.PROD_DESCRICAO FROM PEDIDO PED 
  INNER JOIN ITEM_DO_PEDIDO IP ON IP.PED_NUMERO = PED.PED_NUMERO
  INNER JOIN PRODUTO PRO ON PRO.PRO_CODIGO = IP.PRO_CODIGO
  WHERE PRO.PROD_DESCRICAO = 'QUEIJO';

--16. Listar todos os pedidos que o cliente de código 2 realizou.
SELECT P.PED_NUMERO, C.CLI_CODIGO FROM PEDIDO P
  INNER JOIN CLIENTE C ON C.CLI_CODIGO = P.CLI_CODIGO
  WHERE P.CLI_CODIGO = 2;

--17. Listar a quantidade de pedido que o cliente do código 2 realizou.
SELECT C.CLI_CODIGO, COUNT(*) QTD_PEDIDOS FROM PEDIDO P
  INNER JOIN CLIENTE C ON C.CLI_CODIGO = P.CLI_CODIGO
  WHERE P.CLI_CODIGO = 2 GROUP BY C.CLI_CODIGO;