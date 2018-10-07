

int main (int ar, char **av)
{
	int i;

	i = 0;
	printf("total %d\n", block_size);
	while (i < ar)
	{
		printf((file[i].perm & S_IRUSR) ? "r" : "-");
		printf((file[i].perm & S_IWUSR) ? "w" : "-");
		printf((file[i].perm & S_IXUSR) ? "x" : "-");
		printf((file[i].perm & S_IRGRP) ? "r" : "-");
		printf((file[i].perm & S_IWGRP) ? "w" : "-");
		printf((file[i].perm & S_IXGRP) ? "x" : "-");
		printf((file[i].perm & S_IROTH) ? "r" : "-");
		printf((file[i].perm & S_IWOTH) ? "w" : "-");
		printf((file[i].perm & S_IXOTH) ? "x  " : "-  ");
		printf("%u ", file[i].link);
		printf("%s  ", file[i].user);
		printf("%s  ", file[i].group);
		printf("%*lld ", prev ,file[i].size);
		date_counter = 4;
		while (date_counter <= 15)
			printf("%c", file[i].timestamp[date_counter++]);
		printf(" %s\n", file[i].name);
		i++;
	}
}