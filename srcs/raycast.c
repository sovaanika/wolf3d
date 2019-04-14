/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:47:47 by bbear             #+#    #+#             */
/*   Updated: 2019/04/14 19:06:01 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int main(int argc, char **argv)
{
	t_wolf	*w;
	w = (t_wolf *)malloc(sizeof(*w));
	int	fd = open(argv[1], O_RDONLY);
	validation(w, fd);
	init(w);
	double posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	//screen(512, 384, 0, "Raycaster");
	// while(!done())
	// {
		for(int x = 0; x < w; x++)
		{
	  //calculate ray position and direction
			double cameraX = 2 * x / (double)(w->wid) - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
	  //which box of the map we're in
			int mapX = (int)posX;
			int mapY = (int)posY;

	  //length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

	   //length of ray from one x or y-side to next x or y-side
			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;

	  //what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
	  //calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
	  //perform DDA
			while (hit == 0)
			{
		//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
		//Check if ray has hit a wall
				if (w->map[mapX][mapY].z > 0)
					hit = 1;
			}
	  //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

	  //Calculate height of line to draw on screen
			int lineHeight = (int)(w->hei / perpWallDist);

	  //calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + w->hei / 2;
			if(drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + w->hei / 2;
			if(drawEnd >= w->hei)
				drawEnd = w->hei - 1;

	  //choose wall color
			int color;
			switch((int)w->map[mapX][mapY].z)
			{
				case 1:  color = 0x00FF0000;  break; //red
				case 2:  color = 0x0000FF00;  break; //green
				case 3:  color = 0x000000FF;   break; //blue
				case 4:  color = 127637638;  break; //white
				default: color = 3874988; break; //yellow
			}

	  //give x and y sides different brightness
			if (side == 1)
			{
				color = color / 2;
			}

	  //draw the pixels of the stripe as a vertical line
			verLine(x, drawStart, drawEnd, color);
		}
	//timing for input and FPS counter
		oldTime = time;
		time = getTicks();
		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		printf("%d\n", 1.0 / frameTime); //FPS counter
		redraw();
		cls();

	//speed modifiers
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
	// 	readKeys();
	// //move forward if no wall in front of you
	// 	if (keyDown(SDLK_UP))
	// 	{
	// 		if ((int)w->map[(int)(posX + dirX * moveSpeed)][(int)(posY)].z == 0)
	// 			posX += dirX * moveSpeed;
	// 		if ((int)w->map[(int)(posX)][(int)(posY + dirY * moveSpeed)].z == 0)
	// 			posY += dirY * moveSpeed;
	// 	}
	//move backwards if no wall behind you
	// 	if (keyDown(SDLK_DOWN))
	// 	{
	// 		if ((int)w->map[(int)(posX - dirX * moveSpeed)][(int)(posY)].z == 0) posX -= dirX * moveSpeed;
	// 		if (w->map[(int)(posX)][(int)(posY - dirY * moveSpeed)].z == 0) posY -= dirY * moveSpeed;
	// 	}
	// //rotate to the right
	// 	if (keyDown(SDLK_RIGHT))
	// 	{
	//   //both camera direction and camera plane must be rotated
	// 		double oldDirX = dirX;
	// 		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	// 		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	// 		double oldPlaneX = planeX;
	// 		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	// 		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	// 	}
	// //rotate to the left
	// 	if (keyDown(SDLK_LEFT))
	// 	{
	//   //both camera direction and camera plane must be rotated
	// 		double oldDirX = dirX;
	// 		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	// 		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	// 		double oldPlaneX = planeX;
	// 		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	// 		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	// 	}
	// }
	mlx_loop(w->mlx_ptr);
}