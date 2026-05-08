{
  "cells": [
    {
      "cell_type": "code",
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "f700f9c3",
        "outputId": "bb5cefc1-4ab0-473f-8108-dfad45e68e98"
      },
      "source": [
        "%%writefile reconstruçãohierarquia.cpp\n",
        "#include <iostream>\n",
        "#include <string>\n",
        "\n",
        "using namespace std;\n",
        "\n",
        "// Classe Base para todos os Veículos\n",
        "class Veiculo {\n",
        "protected:\n",
        "    string modelo;\n",
        "public:\n",
        "    Veiculo(string m) : modelo(m) {}\n",
        "    virtual ~Veiculo() {}\n",
        "    virtual void mover() const {\n",
        "        cout << modelo << \" está em movimento.\" << endl;\n",
        "    }\n",
        "};\n",
        "\n",
        "// Classe para veículos que usam combustível líquido\n",
        "class VeiculoCombustao : public Veiculo {\n",
        "public:\n",
        "    VeiculoCombustao(string m) : Veiculo(m) {}\n",
        "    virtual void abastecer() const {\n",
        "        cout << modelo << \" abastecido com gasolina.\" << endl;\n",
        "    }\n",
        "};\n",
        "\n",
        "// Classe para veículos que usam carga elétrica\n",
        "class VeiculoEletrico : public Veiculo {\n",
        "public:\n",
        "    VeiculoEletrico(string m) : Veiculo(m) {}\n",
        "    virtual void carregarBateria() const {\n",
        "        cout << modelo << \" carregado com eletricidade.\" << endl;\n",
        "    }\n",
        "};\n",
        "\n",
        "// Implementações específicas que herdam apenas o que podem cumprir\n",
        "class Carro : public VeiculoCombustao {\n",
        "public:\n",
        "    Carro(string m) : VeiculoCombustao(m) {}\n",
        "};\n",
        "\n",
        "class CarroEletrico : public VeiculoEletrico {\n",
        "public:\n",
        "    CarroEletrico(string m) : VeiculoEletrico(m) {}\n",
        "};\n",
        "\n",
        "// Função que agora é segura pois aceita apenas tipos que realmente abastecem\n",
        "void prepararViagem(const VeiculoCombustao& carro) {\n",
        "    carro.abastecer();\n",
        "}\n",
        "\n",
        "int main() {\n",
        "    Carro meuCarro(\"Sedan Flex\");\n",
        "    CarroEletrico meuTesla(\"Model 3\");\n",
        "\n",
        "    cout << \"--- Veículo a Combustão ---\" << endl;\n",
        "    prepararViagem(meuCarro);\n",
        "    meuCarro.mover();\n",
        "\n",
        "    cout << \"\\n--- Veículo Elétrico ---\" << endl;\n",
        "    meuTesla.carregarBateria(); // Usa o método correto para seu tipo\n",
        "    meuTesla.mover();\n",
        "\n",
        "    return 0;\n",
        "}"
      ],
      "execution_count": null,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Writing reconstruçãohierarquia.cpp\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "a447e4a7",
        "outputId": "af11612e-f3d3-450c-8954-5c2e8b13af10"
      },
      "source": [
        "%%shell\n",
        "./reconstruçãohierarquia.cpp"
      ],
      "execution_count": null,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "--- Veículo a Combustão ---\n",
            "Sedan Flex abastecido com gasolina.\n",
            "Sedan Flex está em movimento.\n",
            "\n",
            "--- Veículo Elétrico ---\n",
            "Model 3 carregado com eletricidade.\n",
            "Model 3 está em movimento.\n"
          ]
        },
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": []
          },
          "metadata": {},
          "execution_count": 21
        }
      ]
    }
  ],
  "metadata": {
    "colab": {
      "provenance": [],
      "authorship_tag": "ABX9TyOmyocIaq/OuVA69XouVESr"
    },
    "kernelspec": {
      "display_name": "Python 3",
      "name": "python3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "nbformat": 4,
  "nbformat_minor": 0
}