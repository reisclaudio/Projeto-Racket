#lang racket

;; Abre o arquivo .geo
(define geo (open-output-file "b1.geo"))
(define geo2 (open-output-file "b2.geo"))
(define geo3 (open-output-file "b3.geo"))

(define qry (open-output-file "q1.qry"))
(define qry2 (open-output-file "q2.qry"))
(define qry3 (open-output-file "q3.qry"))


;; Recebe uma string e um numero a string de ambos concatenados
(define (gerarId string numero)
    (string-append string (number->string numero)))



(define (gerarElementos tamanhoCidade x y w h i contadorQuadras contadorHidrantes contadorRadiosBase boleanoSemaforo arquivo)
    (cond
        [(equal? boleanoSemaforo 0)
           (imprimeSemaforos tamanhoCidade (+ x 127.5) (+ y 87.5) 0 0 arquivo)
           (gerarElementos tamanhoCidade x y w h i contadorQuadras contadorHidrantes contadorRadiosBase 1 arquivo)]

        [(equal? contadorQuadras(- (* tamanhoCidade tamanhoCidade) 1))
           (imprimeQuadras x y w h contadorQuadras arquivo)
           (imprimeHidrantes x y contadorHidrantes arquivo)
           (imprimeRadiosBase x y contadorRadiosBase arquivo)]

        [(equal? i (- tamanhoCidade 1))
           (imprimeQuadras x y w h contadorQuadras arquivo)
           (imprimeHidrantes x y contadorHidrantes arquivo)
           (cond [(equal? (remainder contadorQuadras 2) 0) (imprimeRadiosBase x y contadorRadiosBase arquivo)])
           (gerarElementos tamanhoCidade 25 (+ y 95) w h 0 (+ contadorQuadras 1) (+ contadorHidrantes 1) (+ contadorRadiosBase 1) 1 arquivo)]

        [#t
           (imprimeQuadras x y w h contadorQuadras arquivo)
           (imprimeHidrantes x y contadorHidrantes arquivo)
           (cond [(equal? (remainder contadorQuadras 2) 0) (+ 1 contadorRadiosBase) (imprimeRadiosBase x y contadorRadiosBase arquivo)])
           (gerarElementos tamanhoCidade (+ x 135) y w h (+ i 1) (+ contadorQuadras 1) (+ contadorHidrantes 1) (+ contadorRadiosBase 1) 1 arquivo)]))



(define (imprimeQuadras x y w h id arquivo)
    (display (string-append "q " (gerarId "quadra" id) " " (number->string x) " " (number->string y) " " (number->string w) " " (number->string h) "\n") arquivo))



(define (imprimeHidrantes x y id arquivo)
    (display (string-append "h " (gerarId "hidrante" id) ".1" " " (number->string (+ x 60)) " " (number->string y) "\n") arquivo)
    (display (string-append "h " (gerarId "hidrante" id) ".2" " " (number->string (+ x 120)) " " (number->string (+ y 40)) "\n") arquivo)
    (display (string-append "h " (gerarId "hidrante" id) ".3" " " (number->string (+ x 60)) " " (number->string (+ y 80)) "\n") arquivo)
    (display (string-append "h " (gerarId "hidrante" id) ".4" " " (number->string x) " " (number->string (+ y 40)) "\n") arquivo)
)



(define(imprimeRadiosBase x y id arquivo)
    (display (string-append "rb " (gerarId "radioBase" id) " " (number->string (+ x 60)) " " (number->string (+ y 40)) "\n") arquivo))



(define(imprimeSemaforos tamanhoCidade x y i contadorSemaforos arquivo)
    (cond
        [(equal? contadorSemaforos (* (- tamanhoCidade 1) (- tamanhoCidade 1)))
           (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") arquivo)
        ]

        [(equal? i (- tamanhoCidade 2))
           (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") arquivo)
           (imprimeSemaforos tamanhoCidade 152.5 (+ y 95) 0 (+ contadorSemaforos 1) arquivo)
        ]

        [#t
           (display (string-append "s " (gerarId "semaforo" contadorSemaforos) " " (number->string x) " " (number->string y) "\n") arquivo)
           (imprimeSemaforos tamanhoCidade (+ x 135) y (+ i 1) (+ contadorSemaforos 1) arquivo)
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
    (display "bb evandroforte\n" arquivoQ1)

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
    (display "bb evandroforte\n" arquivoQ2)

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
    (display "bb evandroforte\n" arquivoQ3)
)



;; Gera lista dos elementos (exceto hidrante)
(define (gerarLista elemento numId numMax lista)
  (cond
    [(equal? numId numMax) lista]
    [#t (define listaAux (cons (gerarId elemento numId) lista)) (gerarLista elemento (+ numId 1) numMax listaAux)]))
 
;; Gera lista dos hidrantes
(define (gerarListaHidrante numQuadra numHidrante numMax lista)
  (cond
    [(equal? numQuadra numMax) lista]
    [(equal? numHidrante 4) (define listaAux (cons (string-append (gerarId "hidrante" numQuadra) "." (number->string numHidrante)) lista)) (gerarListaHidrante (+ numQuadra 1) 1 numMax listaAux)]
    [#t (define listaAux (cons (string-append (gerarId "hidrante" numQuadra) "." (number->string numHidrante)) lista)) (gerarListaHidrante numQuadra (+ numHidrante 1) numMax listaAux)]))



;; Bloco de codigo piloto
(gerarElementos 5 25 25 120 80 0 0 0 0 0 geo)
(gerarElementos 10 25 25 120 80 0 0 0 0 0 geo2)
(gerarElementos 15 25 25 120 80 0 0 0 0 0 geo3)

(testesFormas geo geo2 geo3 qry qry2 qry3)

(define listaQuadrasMenor (gerarLista "quadra" 0 25 (list null)))
(define listaQuadrasMedio (gerarLista "quadra" 0 100 (list null)))
(define listaQuadrasMaior (gerarLista "quadra" 0 225 (list null)))
 
(define listaSemaforosMenor (gerarLista "semaforo" 0 16 (list null)))
(define listaSemaforosMedio (gerarLista "semaforo" 0 81 (list null)))
(define listaSemaforosMaior (gerarLista "semaforo" 0 196 (list null)))
 
(define listaRadioBasesMenor (gerarLista "radioBase" 0 13 (list null)))
(define listaRadioBasesMedio (gerarLista "radioBase" 0 51 (list null)))
(define listaRadioBasesMaior (gerarLista "radioBase" 0 113 (list null)))
 
(define listaHidranteMenor (gerarListaHidrante 0 1 25 (list null)))
(define listaHidranteMedio (gerarListaHidrante 0 1 100 (list null)))
(define listaHidranteMaior (gerarListaHidrante 0 1 225 (list null)))

(close-output-port geo)
(close-output-port geo2)
(close-output-port geo3)
(close-output-port qry)
(close-output-port qry2)
(close-output-port qry3)


           