area :: Double -> Double -> Double -> String
area a b c
    | a + b >= c && a + c >= b && b + c >= a =
        show (sqrt (p*(p-a)*(p-b)*(p-c)))
    | otherwise = "-"
    where p = (a + b + c)/2

main :: IO()
main = do
    lado_a <- readLn :: IO Double
    lado_b <- readLn :: IO Double
    lado_c <- readLn :: IO Double
     
    putStrLn(area lado_a lado_b lado_c) -- retorno de string sem aspas