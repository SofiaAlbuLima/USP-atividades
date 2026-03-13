sucessor :: Int -> Int
sucessor x = x + 1

main :: IO()
main = do
    x <- readLn
    print (sucessor x)