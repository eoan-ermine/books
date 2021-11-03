import kotlin.random.Random

fun randomChar(from: Int, until: Int): Char {
    return Random.nextInt(from, until).toChar()
}

fun main() {
    print(buildString {
        append(randomChar(79,80))
        append(randomChar(75,76))
    })
}