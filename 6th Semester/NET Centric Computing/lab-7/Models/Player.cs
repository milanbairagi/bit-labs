using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace lab_7.Models
{
    public class Player
    {
        public int Id { get; set; }

        [StringLength(50, MinimumLength = 3)]
        [Required]
        public required string Name { get; set; }

        [EmailAddress]
        [Required]
        public required string Email { get; set; }

        [Required]
        [Range(18, 40)]
        public int? Age { get; set; }

        [StringLength(50, MinimumLength = 3)]
        [Required]
        public required string Team { get; set; }

        [Display(Name = "Joined Date")]
        [DataType(DataType.Date)]
        public DateTime JoinedDate { get; set; }
    }
}