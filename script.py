import os
import time
import sys
import shutil

print("Make clean")
os.system("cd src && make clean")

time.sleep(1)

print("Make")
os.system("cd src && make siguel")

time.sleep(1)

print("Executando nivel 1")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-del.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsBaixo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsCima.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsBaixo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsDir.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsEsq.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsEsq.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-trnsEsq.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-cbq.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-cbqbordas.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-cbqcentro.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b1.geo -q /q1-testes/q1-dq.qry -o saida")

time.sleep(2)

print("Executando nivel 2")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-del.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-trnsBaixo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-trnsCima.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-trnsBaixo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-trnsDir.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-trnsEsq.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-cbq.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-cbqbordas.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-cbqcentro.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-dq-semaforo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-dq-hidrante.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b2.geo -q /q2-testes/q2-dq-rb.qry -o saida")

time.sleep(2)

print("Executando nivel 3")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-del.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-trnsBaixo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-trnsCima.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-trnsBaixo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-trnsDir.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-trnsEsq.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-cbq.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-cbqbordas.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-cbqcentro.qry -o saida")

os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-dq-semaforo.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-dq-hidrante.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-dq-rb.qry -o saida")
os.system("cd src && ./siguel -e ../casosDeTeste -f b3.geo -q /q3-testes/q3-dq-nenhum.qry -o saida")


time.sleep(2)