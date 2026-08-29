using Microsoft.EntityFrameworkCore;
using lab_6.Models;

namespace lab_6.Data
{
    public class StudentContext : DbContext
    {
        public StudentContext (DbContextOptions<StudentContext> options)
            : base(options)
        {
        }

        public DbSet<Student> Student { get; set; } = default!;
    }
}
