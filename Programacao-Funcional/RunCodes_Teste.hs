main :: IO()
main = do
    x <- readLn :: IO Int
    print (succ x)