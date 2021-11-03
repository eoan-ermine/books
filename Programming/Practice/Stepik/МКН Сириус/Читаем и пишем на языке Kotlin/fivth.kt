fun main() {
    val map = mapOf(
        1 to 'R',
        2 to 'O',
        3 to 'O',
        4 to 'K'
    )
    (3..4).forEach { index ->
        print(map[index])
    }
}