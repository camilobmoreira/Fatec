---------------------
-- CRIA TABLESPACE --
---------------------

CREATE TABLESPACE  TS_BD_pratica_03
DATAFILE  '/mnt/Data/Google-Drive-bustamantecamilo23/FATEC/3_SEM/Programacao_BD/BDs/ts_bd_pratica_03.dbf' SIZE 1M
AUTOEXTEND ON;

------------------
-- CRIA USU�RIO --
------------------

CREATE USER USER_pratica_03
IDENTIFIED BY aluno
DEFAULT TABLESPACE TS_BD_pratica_03
TEMPORARY TABLESPACE TEMP
QUOTA UNLIMITED ON TS_BD_pratica_03;

-----------------
-- PRIVIL�GIOS --
-----------------

GRANT DBA TO USER_pratica_03 WITH ADMIN OPTION;



/* 01 - Crie as tabelas conforme modelo lógico acima e insira pelo menos 5 linhas. Entregar script*/

create table estado (
  est_cod number (4),
  constraint est_pk primary key (est_cod),
  est_estado varchar (30)
);

create table cidade (
  cid_cod number (4),
  constraint cid_pk primary key (cid_cod),
  cid_nome varchar (30),
  est_cod number (4),
  constraint cid_est_fk foreign key (est_cod) references estado (est_cod)
);

create table departamento (
  dep_cod number (4),
  constraint dep_pk primary key (dep_cod),
  dep_descricao varchar (20)
);

create table cargo (
  car_cod number (4),
  constraint car_pk primary key (car_cod),
  car_descricao varchar (20)
);

create table funcionario (
  fun_cod number (4),
  constraint fun_pk primary key (fun_cod),
  fun_logradouro varchar (30),
  fun_nome varchar (30),
  fun_salario number (8, 2),
  car_cod number (4),
  constraint fun_car_fk foreign key (car_cod) references cargo (car_cod),
  fun_cep number (4),
  fun_nro number (4),
  cid_cod number (4),
  constraint fun_cid_fk foreign key (cid_cod) references cidade (cid_cod),
  est_cod number (4),
  constraint fun_est_fk foreign key (est_cod) references estado (est_cod),
  --constraint fun_cid_fk foreign key (cid_cod, est_cod) references cidade (cid_cod, est_cod),
  dep_cod number (4),
  constraint fun_dep_fk foreign key (dep_cod) references departamento (dep_cod)
);

-- insert estado
insert into estado values (1, 'SAO PAULO');
insert into estado values (2, 'MINAS GERAIS');
insert into estado values (3, 'RIO DE JANEIRO');

-- insert cidade
insert into cidade values (1, 'SAO JOSE DOS CAMPOS', 1);
insert into cidade values (2, 'SAO PAULO', 1);
insert into cidade values (3, 'BELO HORIZONTE', 2);
insert into cidade values (4, 'RIO DE JANEIRO', 3);

-- insert departamento
insert into departamento values (1, 'TI');
insert into departamento values (2, 'RECURSOS HUMANOS');

-- insert cargo
insert into cargo values (1, 'GESTOR RH');
insert into cargo values (2, 'DESENVOLVEDOR');
insert into cargo values (3, 'AUXILIAR RH');

-- insert funcionario
insert into funcionario values 
  (1, 'RUA CEL JOAO I', 'ISABEL MARTINS', 9999, 1, 1234, 10, 2, 1, 2);
insert into funcionario values 
  (2, 'AV TEN JOSE III', 'MARIA HELENA', 2000, 3, 1122, 37, 3, 2, 2);
insert into funcionario values 
  (3, 'TV FAUSTO FILHO', 'BARBARA FELICIANO', 5300, 2, 2234, 9, 4, 3, 1);
insert into funcionario values 
  (4, 'AV WALDIR OLAVO', 'JOAO PEDRO', 2300, 2, 1111, 67, 1, 1, 1);
insert into funcionario values 
  (5, 'RUA JOSE ALENCAR I', 'FRANCISCO DA SILVA', 8000, 2, 2332, 23, 1, 1, 1);

/* 02 - Crie a View Funcionário_View com os campos :fun_cod, fun_nome ,
  fun_logradoro, cid_nome, est_estado, carg_descricao, dep_descricao. 
  Apenas será possível a leitura dos dados cadastrais pela view 
  Funcionario_View. */

create or replace view funcionario_view (fun_cod, fun_nome ,fun_logradouro, 
  cid_nome, est_estado, carg_descricao, dep_descricao) as
    select f.FUN_COD, f.FUN_NOME, f.FUN_LOGRADOURO, c.CID_NOME, e.EST_ESTADO, 
    cg.CAR_DESCRICAO, d.DEP_DESCRICAO
    from funcionario f 
    inner join cargo cg on f.CAR_COD = cg.CAR_COD
    inner join cidade c on f.CID_COD = c.CID_COD
    inner join estado e on f.EST_COD = e.EST_COD
    inner join departamento d on f.DEP_COD = d.DEP_COD
    with read only;

/* 03 - Consulte os dados cadastrais pela View (Funcionario_View). */

select * from FUNCIONARIO_VIEW;

/* 04 - Consulte os dados dos funcionários pela tabela Funcionário. */

select * from funcionario;

/* 05 - Insira um funcionário na tabela Funcionário e consulte pela View 
  (Funcionario_View). */

insert into funcionario values 
  (6, 'RUA JOSE ALENCAR I', 'PATRICIA DE MELLO', 8700, 2, 2332, 32, 1, 1, 1);

select * from funcionario_view;

/* 06 - Insira o campo fun_obs na View (Funcionario_View) . 
  OBS: Ele deve existir primeiro na tabela de origem*/

alter table funcionario
  add fun_obs varchar (30);

create or replace view funcionario_view (fun_cod, fun_nome ,fun_logradouro, 
  cid_nome, est_estado, carg_descricao, dep_descricao, fun_obs) as
    select f.FUN_COD, f.FUN_NOME, f.FUN_LOGRADOURO, c.CID_NOME, e.EST_ESTADO, 
    cg.CAR_DESCRICAO, d.DEP_DESCRICAO, f.FUN_OBS
    from funcionario f 
    inner join cargo cg on f.CAR_COD = cg.CAR_COD
    inner join cidade c on f.CID_COD = c.CID_COD
    inner join estado e on f.EST_COD = e.EST_COD
    inner join departamento d on f.DEP_COD = d.DEP_COD
    with read only;


/* 07 - Consulte a definição da View (Funcionario_View) no dicionário de dados. */

select view_name, text from user_views where view_name = 'FUNCIONARIO_VIEW';

/* 08 - A respeito de uma view criada no Oracle, marque com X a (s) resposta(s) 
  correta(s):
  ( ) A. Por meio de uma view os dados apenas podem ser vistos.
  ( ) B.Tabela virtual na qual os dados estão fisicamente armazenados.
  (X) C.Utilizada para evitar que usuários não autorizados tenham acesso a 
    todos os dados de uma tabela.
  ( ) D. Para remover uma view utilizamos o seguinte comando delete 
    view <nome da view> */