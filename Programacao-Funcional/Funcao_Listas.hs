double :: Int -> Int 
-- "::" atribui um tipo à "double"
-- "Int -> Int" significa uma função que recebe um Int e retorna um Int (domínio/contradomínio)
double x = x * 2

quadruple :: Int -> Int
quadruple x = double (double x)

numeros :: [Int]
numeros = [1,2,3,4,5,6]

dobrados :: [Int]
dobrados = map double numeros -- map aplica uma função a todos os elementos da lista

pares :: [Int]
pares = filter even numeros -- filtra pra trabalhar com numeros pares

quadrados :: [Int]
quadrados = map (^2) pares

main :: IO ()
main = print quadrados

