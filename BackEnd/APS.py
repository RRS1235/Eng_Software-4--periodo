# Sistema simples de Avaliação de Restaurantes

restaurantes = {}

def adicionar_avaliacao():
    nome = input("Nome do restaurante: ").title()
    nota = float(input("Nota (0 a 5): "))
    comentario = input("Comentário: ")

    if nome not in restaurantes:
        restaurantes[nome] = []
    
    restaurantes[nome].append({"nota": nota, "comentario": comentario})
    print(f"Avaliação adicionada para {nome}!\n")

def mostrar_avaliacoes():
    if not restaurantes:
        print("Nenhum restaurante avaliado ainda.\n")
        return
    
    for nome, avaliacoes in restaurantes.items():
        notas = [a["nota"] for a in avaliacoes]
        media = sum(notas) / len(notas)
        print(f"\n {nome} — Média: {media:.1f} ({len(avaliacoes)} avaliações)")
        for a in avaliacoes:
            print(f"  - Nota {a['nota']}: {a['comentario']}")

def menu():
    while True:
        print("\n--- Sistema de Avaliação de Restaurantes ---")
        print("1. Adicionar avaliação")
        print("2. Mostrar avaliações")
        print("3. Sair")

        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            adicionar_avaliacao()
        elif opcao == "2":
            mostrar_avaliacoes()
        elif opcao == "3":
            print("Saindo... ")
            break
        else:
            print("Opção inválida! Tente novamente.\n")

menu()
