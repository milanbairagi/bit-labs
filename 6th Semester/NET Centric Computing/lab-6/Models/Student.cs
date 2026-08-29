namespace lab_6.Models
{
    public class Student
    {
        public int Id { get; set; }
        public required string Name { get; set; }
        public required string Email { get; set; }
        public string CreatedAt { get; set; } = DateTime.Now.ToString("dd/MM/yyyy HH:mm:ss");
    }
}
