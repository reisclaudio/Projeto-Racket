#! /usr/bin/env racket
#lang racket/base

;; Abre o arquivo .geo
(define geo (open-output-file "casosDeTeste/b1.geo"))
(define geo2 (open-output-file "casosDeTeste/b2.geo"))
(define geo3 (open-output-file "casosDeTeste/b3.geo"))

;; Abre os arquivos .qry
(define qry (open-output-file "casosDeTeste/q1-testes/q1.qry"))
(define qryDEL (open-output-file "casosDeTeste/q1-testes/q1-del.qry"))
(define qryTransD (open-output-file "casosDeTeste/q1-testes/q1-trnsDir.qry"))
(define qryTransE (open-output-file "casosDeTeste/q1-testes/q1-trnsEsq.qry"))
(define qryTransC (open-output-file "casosDeTeste/q1-testes/q1-trnsCima.qry"))
(define qryTransB (open-output-file "casosDeTeste/q1-testes/q1-trnsBaixo.qry"))
(define qryCBQBordas (open-output-file "casosDeTeste/q1-testes/q1-cbqbordas.qry"))
(define qryCBQCentro (open-output-file "casosDeTeste/q1-testes/q1-cbqcentro.qry"))
(define qryCBQ (open-output-file "casosDeTeste/q1-testes/q1-cbq.qry"))
(define qryDQ (open-output-file "casosDeTeste/q1-testes/q1-dq.qry"))
(define qry2 (open-output-file "casosDeTeste/q2-testes/q2.qry"))
(define qry2DEL (open-output-file "casosDeTeste/q2-testes/q2-del.qry"))
(define qry2TransD (open-output-file "casosDeTeste/q2-testes/q2-trnsDir.qry"))
(define qry2TransE (open-output-file "casosDeTeste/q2-testes/q2-trnsEsq.qry"))
(define qry2TransC (open-output-file "casosDeTeste/q2-testes/q2-trnsCima.qry"))
(define qry2TransB (open-output-file "casosDeTeste/q2-testes/q2-trnsBaixo.qry"))
(define qry2CBQBordas (open-output-file "casosDeTeste/q2-testes/q2-cbqbordas.qry"))
(define qry2CBQCentro (open-output-file "casosDeTeste/q2-testes/q2-cbqcentro.qry"))
(define qry2CBQ (open-output-file "casosDeTeste/q2-testes/q2-cbq.qry"))
(define qry2DQ1 (open-output-file "casosDeTeste/q2-testes/q2-dq-semaforo.qry"))
(define qry2DQ2 (open-output-file "casosDeTeste/q2-testes/q2-dq-hidrante.qry"))
(define qry2DQ3 (open-output-file "casosDeTeste/q2-testes/q2-dq-rb.qry"))
(define qry3 (open-output-file "casosDeTeste/q3-testes/q3.qry"))
(define qry3DEL (open-output-file "casosDeTeste/q3-testes/q3-del.qry"))
(define qry3TransD (open-output-file "casosDeTeste/q3-testes/q3-trnsDir.qry"))
(define qry3TransE (open-output-file "casosDeTeste/q3-testes/q3-trnsEsq.qry"))
(define qry3TransC (open-output-file "casosDeTeste/q3-testes/q3-trnsCima.qry"))
(define qry3TransB (open-output-file "casosDeTeste/q3-testes/q3-trnsBaixo.qry"))
(define qry3CBQBordas (open-output-file "casosDeTeste/q3-testes/q3-cbqbordas.qry"))
(define qry3CBQCentro (open-output-file "casosDeTeste/q3-testes/q3-cbqcentro.qry"))
(define qry3CBQ (open-output-file "casosDeTeste/q3-testes/q3-cbq.qry"))
(define qry3DQ1 (open-output-file "casosDeTeste/q3-testes/q3-dq-semaforo.qry"))
(define qry3DQ2 (open-output-file "casosDeTeste/q3-testes/q3-dq-hidrante.qry"))
(define qry3DQ3 (open-output-file "casosDeTeste/q3-testes/q3-dq-rb.qry"))
(define qry3DQ4 (open-output-file "casosDeTeste/q3-testes/q3-dq-nenhum.qry"))



;; Variavel de aleatoriedade
(define aleatoriedade 0)



;; Listas
(define listaQuadras1 (list null))
(define listaQuadras2 (list null))
(define listaQuadras3 (list null))

(define listaHidrantes1 (list null))
(define listaHidrantes2 (list null))
(define listaHidrantes3 (list null))

(define listaRB1 (list null))
(define listaRB2 (list null))
(define listaRB3 (list null))

(define listaSemaforos1 (list null))
(define listaSemaforos2 (list null))
(define listaSemaforos3 (list null))

;;Cores do SVG
(define cores (list "red" "blue" "yellow" "black" "orange" "pink" "green" "purple" "peru" "lemonchiffon" "midnightblue" null))

;; Recebe uma string e um numero a string de ambos concatenados
(define (gerarId string numero)
    (string-append string (number->string numero)))

;; Coloca o NX, CQ, CH, CR, CS e SW no .geo
(define (gerarComandos arquivo tamanho cores)
  (cond
    [(equal? tamanho 1)
     (display "nx 2 25 100 16 13\n" arquivo)
    ]
    [(equal? tamanho 2)
     (display "nx 2 100 400 81 51\n" arquivo)
    ]
    [(equal? tamanho 3)
     (display "nx 2 225 900 196 113\n" arquivo)
    ]
  )
  (display (string-append "cq " (percorreLista cores (random (- (length cores) 1)) 0) " " (percorreLista cores (random (- (length cores) 1)) 0) " 1\n") arquivo)
  (display (string-append "ch " (percorreLista cores (random (- (length cores) 1)) 0) " " (percorreLista cores (random (- (length cores) 1)) 0) " 1\n") arquivo)
  (display (string-append "cr " (percorreLista cores (random (- (length cores) 1)) 0) " " (percorreLista cores (random (- (length cores) 1)) 0) " 1\n") arquivo)
  (display (string-append "cs " (percorreLista cores (random (- (length cores) 1)) 0) " " (percorreLista cores (random (- (length cores) 1)) 0) " 1\n") arquivo)
  (display "sw 1 1\n" arquivo)
)

(define (gerarElementos tamanhoCidade x y w h i contadorQuadras contadorHidrantes contadorRadiosBase boleanoSemaforo arquivo lista)
    (cond
        [(equal? boleanoSemaforo 0)
           (imprimeSemaforos tamanhoCidade (+ x 127.5) (+ y 87.5) 0 0 arquivo lista)
           (gerarElementos tamanhoCidade x y w h i contadorQuadras contadorHidrantes contadorRadiosBase 1 arquivo lista)]

        [(equal? contadorQuadras(- (* tamanhoCidade tamanhoCidade) 1))
           (imprimeQuadras x y w h contadorQuadras arquivo lista)
           (imprimeHidrantes x y contadorHidrantes arquivo lista)
           (imprimeRadiosBase x y contadorRadiosBase arquivo lista)]

        [(equal? i (- tamanhoCidade 1))
           (imprimeQuadras x y w h contadorQuadras arquivo lista)
           (imprimeHidrantes x y contadorHidrantes arquivo lista)
           (cond [(equal? (remainder contadorQuadras 2) 0) (imprimeRadiosBase x y contadorRadiosBase arquivo lista)])
           (gerarElementos tamanhoCidade 25 (+ y 95) w h 0 (+ contadorQuadras 1) (+ contadorHidrantes 1) (+ contadorRadiosBase 1) 1 arquivo lista)]

        [#t
           (imprimeQuadras x y w h contadorQuadras arquivo lista)
           (imprimeHidrantes x y contadorHidrantes arquivo lista)
           (cond [(equal? (remainder contadorQuadras 2) 0) (+ 1 contadorRadiosBase) (imprimeRadiosBase x y contadorRadiosBase arquivo lista)])
           (gerarElementos tamanhoCidade (+ x 135) y w h (+ i 1) (+ contadorQuadras 1) (+ contadorHidrantes 1) (+ contadorRadiosBase 1) 1 arquivo lista)]))



(define (imprimeQuadras x y w h id arquivo lista)
    (display (string-append "q " (gerarId "quadra" id) " " (number->string x) " " (number->string y) " " (number->string w) " " (number->string h) "\n") arquivo)
    (cond
        [(equal? lista 1) (set! listaQuadras1 (cons (gerarId "quadra" id) listaQuadras1))]
        [(equal? lista 2) (set! listaQuadras2 (cons (gerarId "quadra" id) listaQuadras2))]
        [(equal? lista 3) (set! listaQuadras3 (cons (gerarId "quadra" id) listaQuadras3))]
    )
)



(define (imprimeHidrantes x y id arquivo lista)
    (set! aleatoriedade (random 4))
    (cond [ (> aleatoriedade 1 )
        (display (string-append "h " (gerarId "hidrante" id) ".1" " " (number->string (+ x 60)) " " (number->string y) "\n") arquivo)
        (cond
            [(equal? lista 1) (set! listaHidrantes1 (cons (string-append (gerarId "hidrante" id) ".1") listaHidrantes1))]
            [(equal? lista 2) (set! listaHidrantes2 (cons (string-append (gerarId "hidrante" id) ".1") listaHidrantes2))]
            [(equal? lista 3) (set! listaHidrantes3 (cons (string-append (gerarId "hidrante" id) ".1") listaHidrantes3))]
        )
    ]
    )

    (set! aleatoriedade (random 4))
    (cond [ (> aleatoriedade 1 )
        (display (string-append "h " (gerarId "hidrante" id) ".2" " " (number->string (+ x 120)) " " (number->string (+ y 40)) "\n") arquivo)
        (cond
            [(equal? lista 1) (set! listaHidrantes1 (cons (string-append (gerarId "hidrante" id) ".2") listaHidrantes1))]
            [(equal? lista 2) (set! listaHidrantes2 (cons (string-append (gerarId "hidrante" id) ".2") listaHidrantes2))]
            [(equal? lista 3) (set! listaHidrantes3 (cons (string-append (gerarId "hidrante" id) ".2") listaHidrantes3))]
        )
    ]
    )

    (set! aleatoriedade (random 4))
    (cond [ (> aleatoriedade 1 )
        (display (string-append "h " (gerarId "hidrante" id) ".3" " " (number->string (+ x 60)) " " (number->string (+ y 80)) "\n") arquivo)
        (cond
            [(equal? lista 1) (set! listaHidrantes1 (cons (string-append (gerarId "hidrante" id) ".3") listaHidrantes1))]
            [(equal? lista 2) (set! listaHidrantes2 (cons (string-append (gerarId "hidrante" id) ".3") listaHidrantes2))]
            [(equal? lista 3) (set! listaHidrantes3 (cons (string-append (gerarId "hidrante" id) ".3") listaHidrantes3))]
        )
    ]
    )

    (set! aleatoriedade (random 4))
    (cond [ (> aleatoriedade 1 )
        (display (string-append "h " (gerarId "hidrante" id) ".4" " " (number->string x) " " (number->string (+ y 40)) "\n") arquivo)
        (cond
            [(equal? lista 1) (set! listaHidrantes1 (cons (string-append (gerarId "hidrante" id) ".4") listaHidrantes1))]
            [(equal? lista 2) (set! listaHidrantes2 (cons (string-append (gerarId "hidrante" id) ".4") listaHidrantes2))]
            [(equal? lista 3) (set! listaHidrantes3 (cons (string-append (gerarId "hidrante" id) ".4") listaHidrantes3))]
        )
    ]
    )
)



(define(imprimeRadiosBase x y id arquivo lista)
       (set! aleatoriedade (random 4))
       (cond [ (> aleatoriedade 1 )
            (display (string-append "rb " (gerarId "radioBase" id) " " (number->string (+ x 60)) " " (number->string (+ y 40)) "\n") arquivo)
            (cond
                [(equal? lista 1) (set! listaRB1 (cons (gerarId "radioBase" id) listaRB1))]
                [(equal? lista 2) (set! listaRB2 (cons (gerarId "radioBase" id) listaRB2))]
                [(equal? lista 3) (set! listaRB3 (cons (gerarId "radioBase" id) listaRB3))]
             )
           ]
    )
)



(define(imprimeSemaforos tamanhoCidade x y i contadorSemaforos arquivo lista)
    (cond
        [(equal? contadorSemaforos (* (- tamanhoCidade 1) (- tamanhoCidade 1)))
           (set! aleatoriedade (random 4))
           (cond [ (> aleatoriedade 1 )
               (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") arquivo)
               (cond
                   [(equal? lista 1) (set! listaSemaforos1 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos1))]
                   [(equal? lista 2) (set! listaSemaforos2 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos2))]
                   [(equal? lista 3) (set! listaSemaforos3 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos3))]
               )
               ]
           )
         ]

        [(equal? i (- tamanhoCidade 2))
           (set! aleatoriedade (random 4))
           (cond [ (> aleatoriedade 1 )
               (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") arquivo)
               (cond
                   [(equal? lista 1) (set! listaSemaforos1 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos1))]
                   [(equal? lista 2) (set! listaSemaforos2 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos2))]
                   [(equal? lista 3) (set! listaSemaforos3 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos3))]
               )
               ]
           )
           (imprimeSemaforos tamanhoCidade 152.5 (+ y 95) 0 (+ contadorSemaforos 1) arquivo lista)
        ]

        [#t
           (set! aleatoriedade (random 4))
           (cond [ (> aleatoriedade 1 )
               (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") arquivo)
               (cond
                   [(equal? lista 1) (set! listaSemaforos1 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos1))]
                   [(equal? lista 2) (set! listaSemaforos2 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos2))]
                   [(equal? lista 3) (set! listaSemaforos3 (cons (gerarId "semaforo" contadorSemaforos) listaSemaforos3))]
               )
               ]
           )
           (imprimeSemaforos tamanhoCidade (+ x 135) y (+ i 1) (+ contadorSemaforos 1) arquivo lista)
        ]
    )
)



(define(testesFormas arquivoG1 arquivoG2 arquivoG3 arquivoQ1 arquivoQ2 arquivoQ3)
    (define x1 (random 660)) (define y1 (random 460))
    (display (string-append "c " "1 " "15 " (number->string x1) " " (number->string y1) " midnightblue " "black" "\n") arquivoG1)
              
    (define x2 (random 660)) (define y2 (random 460))
    (display (string-append "r " "2 " "30 " "30 " (number->string x2) " " (number->string y2) " midnightblue " "black" "\n") arquivoG1)

    ;; Valores de teste 1
    (define t1 (random 660)) (define t2 (random 460)) (define t3 (random 660)) (define t4 (random 460)) 

    ;; Testes 1
    (display "o? 1 2\n" arquivoQ1)
    (display (string-append "i? 1 " (number->string t1) " " (number->string t2) "\n") arquivoQ1)
    (display (string-append "i? 2 " (number->string t3) " " (number->string t4) "\n") arquivoQ1)
    (display "d? 1 2\n" arquivoQ1)
    (display "bb suf midnightblue\n" arquivoQ1)

    (define x3 (random 1335))
    (define y3 (random 935))
    (display (string-append "c " "1 " "15 " (number->string x3) " " (number->string y3) " midnightblue " "black" "\n") arquivoG2)

    (define x4 (random 1335))
    (define y4 (random 935))
    (display (string-append "r " "2 " "30 " "30 " (number->string x4) " " (number->string y4) " midnightblue " "black" "\n") arquivoG2)

    ;; Valores de teste 2
    (define t5 (random 1335)) (define t6 (random 935)) (define t7 (random 1335)) (define t8 (random 935))

    ;; Testes 2
    (display "o? 1 2\n" arquivoQ2)
    (display (string-append "i? 1 " (number->string t5) " " (number->string t6) "\n") arquivoQ2)
    (display (string-append "i? 2 " (number->string t7) " " (number->string t8) "\n") arquivoQ2)
    (display "d? 1 2\n" arquivoQ2)
    (display "bb suf midnightblue\n" arquivoQ2)

    (define x5 (random 2010))
    (define y5 (random 1410))
    (display (string-append "c " "1 " "15 " (number->string x5) " " (number->string y5) " midnightblue " "black" "\n") arquivoG3)

    (define x6 (random 2010))
    (define y6 (random 1410))
    (display (string-append "r " "2 " "30 " "30 " (number->string x6) " " (number->string y6) " midnightblue " "black" "\n") arquivoG3)

    ;; Valores de teste 3
    (define t9 (random 2010)) (define t10 (random 1410)) (define t11 (random 2010)) (define t12 (random 1410))

    ;; Testes 3
    (display "o? 1 2\n" arquivoQ3)
    (display (string-append "i? 1 " (number->string t9) " " (number->string t10) "\n") arquivoQ3)
    (display (string-append "i? 2 " (number->string t11) " " (number->string t12) "\n") arquivoQ3)
    (display "d? 1 2\n" arquivoQ3)
    (display "bb suf indigo\n" arquivoQ3)
)

;; Função que percorre a lista
(define (percorreLista lista indice i)
  (cond
      [(equal? indice i)
         (car lista)]
  [#t
     (percorreLista (cdr lista) indice (+ i 1))]))

;; Consulta cbq
(define (geraCBQ lista cores)
  (cond
    [(equal? lista 1)
     (display (string-append "cbq " (number->string (random 685)) " " (number->string (random 460)) " " (number->string (random 50 100)) " " (percorreLista cores (random (- (length cores) 1)) 0) "\n") qryCBQBordas)
     (display (string-append "cbq " (number->string (random 145 565)) " " (number->string (random 95 380)) " " (number->string (random 50 100)) " " (percorreLista cores (random (- (length cores) 1)) 0) "\n") qryCBQCentro)
     (display (string-append "cbq " (number->string (random 685)) " " (number->string (460)) " " (number->string (random 50)) " " (percorreLista cores (random (- (length cores) 1)) 0) "\n") qryCBQBordas)
    ]
  )
)

;; Consulta crd
(define (geraDEL lista)
  (cond
      [(equal? lista 1)
         (define indice ( random (- (length listaQuadras1) 1)))
         (display (string-append "crd?" " " (percorreLista listaQuadras1 indice 0) "\n") qryDEL)
         (display (string-append "del" " " (percorreLista listaQuadras1 indice 0) "\n") qryDEL)
         (display (string-append "crd?" " " (percorreLista listaQuadras1 indice 0) "\n") qryDEL)
         (set! indice (random (- (length listaHidrantes1) 1)))
         (display (string-append "crd?" " " (percorreLista listaHidrantes1 indice 0) "\n") qryDEL)
         (display (string-append "del" " " (percorreLista listaHidrantes1 indice 0) "\n") qryDEL)
         (display (string-append "crd?" " " (percorreLista listaHidrantes1 indice 0) "\n") qryDEL)
         (set! indice (random (- (length listaSemaforos1) 1)))
         (display (string-append "crd?" " " (percorreLista listaSemaforos1 indice 0) "\n") qryDEL)
         (display (string-append "del" " " (percorreLista listaSemaforos1 indice 0) "\n") qryDEL)
         (display (string-append "crd?" " " (percorreLista listaSemaforos1 indice 0) "\n") qryDEL)
         (set! indice (random (- (length listaRB1) 1)))
         (display (string-append "crd?" " " (percorreLista listaRB1 indice 0) "\n") qryDEL)
         (display (string-append "del" " " (percorreLista listaRB1 indice 0) "\n") qryDEL)
         (display (string-append "crd?" " " (percorreLista listaRB1 indice 0) "\n") qryDEL)]

      [(equal? lista 2)
         (define indice (random (- (length listaQuadras2) 1)))
         (display (string-append "crd?" " " (percorreLista listaQuadras2 indice 0) "\n") qry2DEL)
         (display (string-append "del" " " (percorreLista listaQuadras2 indice 0) "\n") qry2DEL)
         (display (string-append "crd?" " " (percorreLista listaQuadras2 indice 0) "\n") qry2DEL)
         (set! indice (random (- (length listaHidrantes2) 1)))
         (display (string-append "crd?" " " (percorreLista listaHidrantes2 indice 0) "\n") qry2DEL)
         (display (string-append "del" " " (percorreLista listaHidrantes2 indice 0) "\n") qry2DEL)
         (display (string-append "crd?" " " (percorreLista listaHidrantes2 indice 0) "\n") qry2DEL)
         (set! indice (random (- (length listaSemaforos2) 1)))
         (display (string-append "crd?" " " (percorreLista listaSemaforos2 indice 0) "\n") qry2DEL)
         (display (string-append "del" " " (percorreLista listaSemaforos2 indice 0) "\n") qry2DEL)
         (display (string-append "crd?" " " (percorreLista listaSemaforos2 indice 0) "\n") qry2DEL)
         (set! indice (random (- (length listaRB2) 1)))
         (display (string-append "crd?" " " (percorreLista listaRB2 indice 0) "\n") qry2DEL)
         (display (string-append "del" " " (percorreLista listaRB2 indice 0) "\n") qry2DEL)
         (display (string-append "crd?" " " (percorreLista listaRB2 indice 0) "\n") qry2DEL)]
      
      [(equal? lista 3)
         (define indice (random (- (length listaQuadras3) 1)))
         (display (string-append "crd?" " " (percorreLista listaQuadras3 indice 0) "\n") qry3DEL)
         (display (string-append "del" " " (percorreLista listaQuadras3 indice 0) "\n") qry3DEL)
         (display (string-append "crd?" " " (percorreLista listaQuadras3 indice 0) "\n") qry3DEL)
         (set! indice (random (- (length listaHidrantes3) 1)))
         (display (string-append "crd?" " " (percorreLista listaHidrantes3 indice 0) "\n") qry3DEL)
         (display (string-append "del" " " (percorreLista listaHidrantes3 indice 0) "\n") qry3DEL)
         (display (string-append "crd?" " " (percorreLista listaHidrantes3 indice 0) "\n") qry3DEL)
         (set! indice (random (- (length listaSemaforos3) 1)))
         (display (string-append "crd?" " " (percorreLista listaSemaforos3 indice 0) "\n") qry3DEL)
         (display (string-append "del" " " (percorreLista listaSemaforos3 indice 0) "\n") qry3DEL)
         (display (string-append "crd?" " " (percorreLista listaSemaforos3 indice 0) "\n") qry3DEL)
         (set! indice (random (- (length listaRB3) 1)))
         (display (string-append "crd?" " " (percorreLista listaRB3 indice 0) "\n") qry3DEL)
         (display (string-append "del" " " (percorreLista listaRB3 indice 0) "\n") qry3DEL)
         (display (string-append "crd?" " " (percorreLista listaRB3 indice 0) "\n") qry3DEL)]))

;; Consulta trns
(define (geraTrns arquivo tamanho tipo)
  (cond
    [(equal? tamanho 1)
     (cond
       [(equal? tipo "d")
        (display (string-append "trns " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 1 100)) " 0\n") arquivo)
       ]
       [(equal? tipo "e")
        (display (string-append "trns " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random -100 -1)) " 0\n") arquivo)
       ]
       [(equal? tipo "c")
        (display (string-append "trns " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " 0 " (number->string (random -100 -1)) "\n") arquivo)
       ]
       [(equal? tipo "b")
        (display (string-append "trns " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " " (number->string (random 660)) " 0 " (number->string (random 1 100)) "\n") arquivo)
       ]
     )
    ]
    [(equal? tamanho 2)
     (cond
       [(equal? tipo "d")
        (display (string-append "trns " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1 100)) " 0\n") arquivo)
       ]
       [(equal? tipo "e")
        (display (string-append "trns " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random -100 -1)) " 0\n") arquivo)
       ]
       [(equal? tipo "c")
        (display (string-append "trns " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " 0 " (number->string (random -100 -1)) "\n") arquivo)
       ]
       [(equal? tipo "b")
        (display (string-append "trns " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " " (number->string (random 1335)) " 0 " (number->string (random 1 100)) "\n") arquivo)
       ]
     )
    ]
    [(equal? tamanho 3)
     (cond
       [(equal? tipo "d")
        (display (string-append "trns " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 1 100)) " 0\n") arquivo)
       ]
       [(equal? tipo "e")
        (display (string-append "trns " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random -100 -1)) " 0\n") arquivo)
       ]
       [(equal? tipo "c")
        (display (string-append "trns " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " 0 " (number->string (random -100 -1)) "\n") arquivo)
       ]
       [(equal? tipo "b")
        (display (string-append "trns " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " " (number->string (random 2010)) " 0 " (number->string (random 1 100)) "\n") arquivo)
       ]
     )
    ]
   )
)



(define (geraDQ)

  ;; Complexidade 1
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaHidrantes1 (random (-(length listaHidrantes1)1))0) " " (number->string(random 100 350))) qryDQ)

  ;; Complexidade 2
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaSemaforos2 (random (-(length listaSemaforos2)1))0) " " (number->string(random 100 450))) qry2DQ1)
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaHidrantes2 (random (-(length listaHidrantes2)1))0) " " (number->string(random 100 450))) qry2DQ2)
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaRB2 (random (-(length listaRB2)1))0) " " (number->string(random 100 450))) qry2DQ3)

  ;; Complexidade 3
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaSemaforos3 (random (-(length listaSemaforos3)1))0) " " (number->string(random 100 650))) qry3DQ1)
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaHidrantes3 (random (-(length listaHidrantes3)1))0) " " (number->string(random 100 650))) qry3DQ2)
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaRB3 (random (-(length listaRB3)1))0) " " (number->string(random 100 650))) qry3DQ3)
  (display (string-append "dq L" (number->string(random 1 3)) " " (percorreLista listaRB3 (random (-(length listaRB3)1))0) " " "1") qry3DQ4)
)




;; Bloco de codigo piloto
(gerarComandos geo 1 cores)
(gerarComandos geo2 2 cores)
(gerarComandos geo3 3 cores)
(gerarElementos 5 25 25 120 80 0 0 0 0 0 geo 1)
(gerarElementos 10 25 25 120 80 0 0 0 0 0 geo2 2)
(gerarElementos 15 25 25 120 80 0 0 0 0 0 geo3 3)

(testesFormas geo geo2 geo3 qry qry2 qry3)
(geraDEL 1)
(geraDEL 2)
(geraDEL 3)
(geraTrns qryTransD 1 "d")
(geraTrns qryTransE 1 "e")
(geraTrns qryTransC 1 "c")
(geraTrns qryTransB 1 "b")
(geraTrns qry2TransD 2 "d")
(geraTrns qry2TransE 2 "e")
(geraTrns qry2TransC 2 "c")
(geraTrns qry2TransB 2 "b")
(geraTrns qry3TransD 3 "d")
(geraTrns qry3TransE 3 "e")
(geraTrns qry3TransC 3 "c")
(geraTrns qry3TransB 3 "b")

(geraDQ)

;; Fecha os arquivos
(close-output-port geo)
(close-output-port geo2)
(close-output-port geo3)
(close-output-port qry)
(close-output-port qry2)
(close-output-port qry3)
(close-output-port qryCBQBordas)
(close-output-port qryCBQCentro)
(close-output-port qry2CBQ)
(close-output-port qry2CBQBordas)
(close-output-port qry2CBQCentro)
(close-output-port qry2CBQ)
(close-output-port qry3CBQBordas)
(close-output-port qry3CBQCentro)
(close-output-port qry3CBQ)
(close-output-port qryDEL)
(close-output-port qry2DEL)
(close-output-port qry3DEL)
(close-output-port qryTransD)
(close-output-port qryTransE)
(close-output-port qryTransC)
(close-output-port qryTransB)
(close-output-port qry2TransD)
(close-output-port qry2TransE)
(close-output-port qry2TransC)
(close-output-port qry2TransB)
(close-output-port qry3TransD)
(close-output-port qry3TransE)
(close-output-port qry3TransC)
(close-output-port qry3TransB)
(close-output-port qryDQ)
(close-output-port qry2DQ1)
(close-output-port qry2DQ2)
(close-output-port qry2DQ3)
(close-output-port qry3DQ1)
(close-output-port qry3DQ2)
(close-output-port qry3DQ3)
(close-output-port qry3DQ4)





