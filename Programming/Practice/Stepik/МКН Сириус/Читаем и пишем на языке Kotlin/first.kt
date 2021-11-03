first.ktimport java.io.InputStreamReader

fun main() {
    InputStreamReader(System.`in`).use { reader ->
        var sum = 0                                    
        reader.forEachLine { line ->
            try {
                val numbers = line.trim().split(" ").map { it.toInt() }
                val odd_count = numbers.count { it % 2 == 1 }
                val even_count = numbers.count{ it % 2 == 0 }
                
                if(odd_count > even_count) {
                     sum += numbers.sum()   
                }
            } catch (e: Exception) { }
        }
        print(sum)
    }
}