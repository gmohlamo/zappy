server = server

broadcast = broadcast

FLAGS = gcc -I./includes -I./libft -L./libft
     
part1 = obj/part1/add_gfx.o obj/part1/append_client.o obj/part1/append_connection.o\
			obj/part1/assign_conn.o obj/part1/check_team.o obj/part1/clean_up.o\
			obj/part1/close_connection.o obj/part1/find_client.o obj/part1/find_conn.o\
			obj/part1/init_client.o obj/part1/init_game.o obj/part1/init_teams.o\
			obj/part1/main.o obj/part1/parse_args.o obj/part1/process_line.o\
			obj/part1/process_or_close.o obj/part1/remove_conn.o obj/part1/run_game.o\
			obj/part1/usage_exit.o

part2 = obj/part2/advance.o obj/part2/broadcast.o obj/part2/connect_nbr.o\
		obj/part2/death.o obj/part2/fork.o obj/part2/incantation.o\
		obj/part2/inventory.o obj/part2/kick.o obj/part2/left.o\
		obj/part2/put.o obj/part2/right.o obj/part2/see.o\
		obj/part2/take.o\

part3 = obj/part3/block_contents.o obj/part3/nbr_client.o obj/part3/send_eggs.o\
		obj/part3/send_init_gfx.o obj/part3/update_gfx.o obj/part3/update_gfx_client.o\

part4 = obj/part4/client_advance_gfx.o obj/part4/client_death_update.o\

part5 = obj/part5/append_line.o\

part6 = obj/part6/ft_strjoinint.o obj/part6/client_nbr.o\

broadcast = obj/broadcast/broadcast.o obj/broadcast/horizontal_calc.o\
		obj/broadcast/squares.o obj/broadcast/vertical_calc.o obj/broadcast/hyp_calc.o\
		obj/broadcast/diagonal_calc.o obj/broadcast/line_intersection.o\
		obj/broadcast/line.o obj/broadcast/oob.o\

all : $(server)

broad : $(broadcast)
	$(FLAGS) -o broad $(broadcast) -lm libft/libft.a -g

$(server) : $(part1) $(part2) $(part3) $(part4) $(part5) $(part6)
	make -C libft 
	$(FLAGS) -o $(server) $(part1) $(part2) $(part3) $(part4) $(part5) $(part6) libft/libft.a -g

$(part1): obj/part1/%.o: src/%.c
	$(FLAGS) -c src/$*.c -o $@

$(part2): obj/part2/%.o: src/logic/client/%.c
	$(FLAGS) -c src/logic/client/$*.c -o $@

$(part3): obj/part3/%.o: src/logic/gfx/%.c
	$(FLAGS) -c src/logic/gfx/$*.c -o $@

$(part4): obj/part4/%.o: src/logic/gfx/client_info/%.c
	$(FLAGS) -c src/logic/gfx/client_info/$*.c -o $@

$(part5): obj/part5/%.o: src/logic/%.c
	$(FLAGS) -c src/logic/$*.c -o $@

$(part6): obj/part6/%.o: src/util/%.c
	$(FLAGS) -c src/util/$*.c -o $@

$(broadcast): obj/broadcast/%.o: src/logic/client/broadcast/%.c
	$(FLAGS) -c src/logic/client/broadcast/$*.c -lm -o $@

clean:
	make clean -C libft/
	rm -f $(part1) $(part2) $(part3) $(part4) $(part5) $(part6)

fclean: clean
	make fclean -C libft/
	rm -rf $(server)

re: fclean all