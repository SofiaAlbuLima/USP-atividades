tamanho :: [a] -> Int
tamanho [] = 0 -- tamanho da lista vazia "[]" é zero
tamanho (_:xs) = 1 + tamanho xs
    -- "(_:xs)" ignore o primeiro elemento, xs é o resto da lista

main :: IO()
main = print (tamanho [1,2,3])