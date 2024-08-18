nopcao = 0
iqmeia = 0
ipmeia = 0
iqtoca = 0
iptoca = 0
tgmeias = 0
tgtocas = 0
tgv = 0
reaismeia = 0
reaistoca = 0

nome = input ('Qual o seu nome? ')
while nopcao == 0 :
    print ('bem vinda(o)',nome)
    print ('')
    print ('              VENDAS')
    print (iqmeia,' meias vendidas por R$',ipmeia,' TOTAL: R$',reaismeia)
    print (iqtoca,' tocas vendidas por R$',iptoca,' TOTAL: R$',reaistoca)
    print ('             TOTAL DE VENDAS: R$',reaismeia+reaistoca)
    print ('OPCOES:')
    print ('1 - Venda')
    print ('2 - Configuração de produtos')
    print ('3 - Sair')
    opcao = input ('Insira o numero da sua opcao ')
    nopcao = int(opcao)
    if nopcao == 1 :

        print ('Qual produto você está vendendo?')
        print ('')
        print ('1 - Meias')
        print ('2 - Tocas')
        print ('3 - Voltar ao menu inicial')
        opcaoproduto = input ('Insira o numero da sua opcao')
        nopcaoproduto = int(opcaoproduto)
        if nopcaoproduto == 1 :
            qmeia = input ('Quantas meias voce vendeu?')
            iqmeia = int (qmeia)
            pmeia = input ('Qual o preco de cada meia vendida?')
            ipmeia = int (pmeia)
            reaismeia = ipmeia*iqmeia
            print ('Você vendeu R$',reaismeia,' de meias')
            opcao = input ('')
            nopcao = 0
        if nopcaoproduto ==2 :
            qtoca = input ('Quantas tocas voce vendeu?')
            iqtoca = int (qtoca)
            ptoca = input ('Qual o preco de cada meia vendida?')
            iptoca = int (ptoca)
            reaistoca = iptoca*iqtoca
            print ('Você vendeu R$',reaistoca, 'de tocas')
            opcao = input ('')
            nopcao = 0
    if nopcao == 2 :
        opcao = input ('A função de configurar produtos estará disponível em breve aperte qualquer tecla para continuar')
        nopcao = 0
