using Microsoft.EntityFrameworkCore;
using lab_7.Models;

namespace lab_7.Data
{
    public class PlayerContext : DbContext
    {
        public PlayerContext(DbContextOptions<PlayerContext> options) : base(options)
        {
        }

        public DbSet<Player> Players { get; set; }
    }
}