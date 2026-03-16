area :: Float -> Float -> Float -> Float
area a b c= sqrt (p*(p-a)*(p-b)*(p-c))
    where p = (a + b + c)/2

main :: IO()
main = do
    a <- readLn
    b <- readLn
    c <- readLn
     
    print (area a b c)