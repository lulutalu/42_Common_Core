			/////////////////////////////////////////////////
/*	//		find_mini_value(&ahead, &aproc);
			linked_list_linear(&bhead);
			find_biggest_value(&bhead, &bproc);
			linked_list_circle(&bhead);
	//		linked_list_circle(&ahead);
			while (bhead->prev->pos != bproc.aim->pos) //|| ahead->prev->pos != aproc.aim->pos)
			{
				if (bhead->prev->pos != bproc.aim->pos)// && ahead->prev->pos != aproc.aim->pos)
				{
					if (bproc.temp <= chunk / 2)//dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
						rotate_stack(&bhead, 'b');
					else if (bproc.temp > chunk / 2)//dl.ymax / 4 && aproc.temp > dl.ymax / 4)
						reverse_rotate_stack(&bhead, 'b');
					else if (bproc.temp <= dl.ymax / 4 && aproc.temp > dl.ymax / 4)
					{
						rotate_stack(&bhead, 'b');
						reverse_rotate_stack(&ahead, 'a');
					}
					else if (bproc.temp > dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
					{
						reverse_rotate_stack(&bhead, 'b');
						rotate_stack(&ahead, 'a');
					}
				}
				else if (bhead->prev->pos == bproc.aim->pos)
				{
					if (aproc.temp <= dl.ymax / 4)
						rotate_stack(&ahead, 'a');
					else
						reverse_rotate_stack(&ahead, 'a');
				}
				else if (ahead->prev->pos == aproc.aim->pos)
				{
					if (bproc.temp <= dl.ymax / 4)
						rotate_stack(&bhead, 'b');
					else
						reverse_rotate_stack(&bhead, 'b');
				}*/
				linked_list_circle(&bhead);
	//			linked_list_circle(&ahead);
			}
	//		stack_visualisation(&ahead, &bhead);
			///////////////////////////////////////////////////////////////////////////
			linked_list_linear(&bhead);
//			linked_list_linear(&ahead);
	//		while (invert_check_sort(&bhead) == 0 || check_sort(&ahead) == 0)
			while (invert_check_sort(&bhead) == 0)
			{
	//			linked_list_linear(&ahead);
				linked_list_linear(&bhead);
				find_next_big(&bhead, &bproc);	
	//			find_next_mini(&ahead, &aproc);
	//			printf("Target a : %d\nTarget b : %d\n", aproc.curaim->pos, bproc.curaim->pos);
	//			/////////////////////////////////////////////////////////////////////////
				if (bproc.temp <= chunk / 2)//dl.ymax / 4)
				{
					while (bhead != bproc.curaim)
						rotate_stack(&bhead, 'b');
	/*				if (bhead == bproc.curaim)
					{
						while (ahead != aproc.curaim)
							rotate_stack(&ahead, 'a');
					}
					if (ahead == aproc.curaim)
					{
						while (bhead != bproc.curaim)
							rotate_stack(&bhead, 'b');
					}*/
				}
				else if (bproc.temp > chunk / 2)//dl.ymax / 4)
				{
					while (bhead != bproc.curaim)
						reverse_rotate_stack(&bhead, 'b');
	/*				if (bhead == bproc.curaim)
					{
						while (ahead != aproc.curaim)
							reverse_rotate_stack(&ahead, 'a');
					}
					if (ahead == aproc.curaim)
					{
						while (bhead != bproc.curaim)
							reverse_rotate_stack(&bhead, 'b');
					}*/
				}
	/*			else if (bproc.temp <= dl.ymax / 4 && aproc.temp > dl.ymax / 4)
				{
					while (bhead != bproc.curaim && ahead != aproc.curaim)
					{
						rotate_stack(&bhead, 'b');
						reverse_rotate_stack(&ahead, 'a');
					}
					if (bhead == bproc.curaim)
					{
						while (ahead != aproc.curaim)
							reverse_rotate_stack(&ahead, 'a');
					}
					if (ahead == aproc.curaim)
					{
						while (bhead != bproc.curaim)
							rotate_stack(&bhead, 'b');
					}
				}
				else if (bproc.temp > dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
				{
					while (bhead != bproc.curaim && ahead != aproc.curaim)
					{
						reverse_rotate_stack(&bhead, 'b');
						rotate_stack(&ahead, 'a');
					}
					if (bhead == bproc.curaim)
					{
						while (ahead != aproc.curaim)
							rotate_stack(&ahead, 'a');
					}
					if (ahead == aproc.curaim)
					{
						while (bhead != bproc.curaim)
							reverse_rotate_stack(&bhead, 'b');
					}
				}*/
				///////////////////////////////////////////////////////////////
				if (bhead == bproc.curaim)
				{
	//				find_lst(&ahead, aproc.aim, &aproc);
					find_lst(&bhead, bproc.aim, &bproc);
	//				stack_visualisation(&ahead, &bhead);
	//				printf("Temp a : %d\nTemp b : %d\n", aproc.temp, bproc.temp);
	//				printf("Comp : %d\n", dl.ymax / 4);
	//				printf("Target a : %d\nTarget b : %d\n", aproc.aim->pos, bproc.aim->pos);
					if (bproc.temp <= chunk / 2)//dl.ymax / 4)
					{
						while (bhead->next != bproc.aim)
						{
							swap_stack(&bhead, 'b');
							rotate_stack(&bhead, 'b');
						}
	/*					if (bhead->next == bproc.aim)
						{
							while (ahead->next != aproc.aim)
							{
								swap_stack(&ahead, 'a');
								rotate_stack(&ahead, 'a');
							}
						}
						else if (ahead->next == aproc.aim)
						{
							while (bhead->next != bproc.aim)
							{
								swap_stack(&bhead, 'b');
								rotate_stack(&bhead, 'b');
							}
						}*/
						swap_stack(&bhead, 'b');
	//					stack_visualisation(&ahead, &bhead);
					}
					else if (bproc.temp > chunk / 2)//dl.ymax / 4)
					{
	//					linked_list_circle(&ahead);
						linked_list_circle(&bhead);
						while (bhead->prev != bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
							swap_stack(&bhead, 'b');
	//						stack_visualisation(&ahead, &bhead);
	//						linked_list_circle(&ahead);
							linked_list_circle(&bhead);
						}
	/*					if (ahead->prev == aproc.aim)
						{
							reverse_rotate_stack(&ahead, 'a');
							while (bhead->prev != bproc.aim)
							{
								reverse_rotate_stack(&bhead, 'b');
								swap_stack(&bhead, 'b');
								linked_list_circle(&bhead);
							}
							if (bhead->prev == bproc.aim)
								reverse_rotate_stack(&bhead, 'b');
						}*/
						if (bhead->prev == bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
	/*						while (ahead->prev != aproc.aim)
							{
								reverse_rotate_stack(&ahead, 'a');
								swap_stack(&ahead, 'a');
								linked_list_circle(&ahead);
							}
							if (ahead->prev == aproc.aim)
								reverse_rotate_stack(&ahead, 'a');*/
						}
	//					stack_visualisation(&ahead, &bhead);
					}
	/*				else if (aproc.temp <= dl.ymax / 4 && bproc.temp > dl.ymax / 4)
					{
						linked_list_circle(&bhead);
						while (ahead->next != aproc.aim && bhead->prev != bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
							swap_both(&ahead, &bhead);
							rotate_stack(&ahead, 'a');
							linked_list_circle(&bhead);
						}
						if (ahead->next == aproc.aim)
						{
							swap_stack(&ahead, 'a');
							while (bhead->prev != bproc.aim)
							{
								reverse_rotate_stack(&bhead, 'b');
								swap_stack(&bhead, 'b');
								linked_list_circle(&bhead);
							}
							if (bhead->prev == bproc.aim)
								reverse_rotate_stack(&bhead, 'b');
						}
						else if (bhead->prev == bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
							while (ahead->next != aproc.aim)
							{
								swap_stack(&ahead, 'a');
								rotate_stack(&ahead, 'a');
							}
							if (ahead->next == aproc.aim)
								swap_stack(&ahead, 'a');
						}
	//					stack_visualisation(&ahead, &bhead);
					}
					else if (aproc.temp > dl.ymax / 4 && bproc.temp <= dl.ymax / 4)
					{
						linked_list_circle(&ahead);
						while (ahead->prev != aproc.aim && bhead->next != bproc.aim)
						{
							reverse_rotate_stack(&ahead, 'a');
							swap_both(&ahead, &bhead);
							rotate_stack(&bhead, 'b');
	//						stack_visualisation(&ahead, &bhead);
							linked_list_circle(&ahead);
						}
						if (bhead->next == bproc.aim)
						{
							reverse_rotate_stack(&ahead, 'a');
							swap_both(&ahead, &bhead);
							while (ahead->prev != aproc.aim)
							{
								reverse_rotate_stack(&ahead, 'a');
								swap_stack(&ahead, 'a');
								linked_list_circle(&ahead);
							}
							if (ahead->prev == aproc.aim)
								reverse_rotate_stack(&ahead, 'a');
						}
						else if (ahead->prev == aproc.aim)
						{
							reverse_rotate_stack(&ahead, 'a');
							while (bhead->next != bproc.aim)
							{
								swap_stack(&bhead, 'b');
								rotate_stack(&bhead, 'b');
							}
							if (bhead->next == bproc.aim)
								swap_stack(&bhead, 'b');
						}
	//					stack_visualisation(&ahead, &bhead);
					}*/
				}
				///////////////////////////////////////////////////////////
	//			stack_visualisation(&ahead, &bhead);
				bproc.aim = bproc.curaim;
				aproc.aim = aproc.curaim;
