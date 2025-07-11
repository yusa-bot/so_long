// map_utils.c
char **read_map(const char *filepath)
{
    int     fd;
    char    *all_content;
    char    **map;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        print_error("Cannot open map file");

    all_content = read_all_lines(fd); // ここで全体を1つの文字列として読む
    close(fd);
    if (!all_content)
        print_error("Failed to read map file");

    map = ft_split(all_content, '\n'); // 改行で分割して2次元配列に
    free(all_content);
    if (!map)
        print_error("Failed to split map content");

    return map;
}

char **map = {
    "11111",
    "1P0C1",
    "1C0E1",
    "11111",
    NULL
};
