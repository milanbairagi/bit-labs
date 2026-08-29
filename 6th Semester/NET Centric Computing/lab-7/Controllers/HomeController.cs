using Microsoft.AspNetCore.Mvc;
using lab_7.Data;
using lab_7.Models;
using Microsoft.EntityFrameworkCore;

namespace lab_7.Controllers;

public class HomeController : Controller
{
    private readonly PlayerContext _context;

    public HomeController(PlayerContext context)
    {
        _context = context;
    }

    public async Task<IActionResult> Index()
    {
        return View(await _context.Players.ToListAsync());
    }

    public IActionResult Create()
    {
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Create([Bind("Id,Name,Email,Age,Team,JoinedDate")] Player player)
    {
        Console.WriteLine("Data received: " + player.Name + ", " + player.Email + ", " + player.Age + ", " + player.Team + ", " + player.JoinedDate);
        
        if (ModelState.IsValid)
        {
            _context.Add(player);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }
        // Print model state errors for debugging
        foreach (var modelState in ModelState)
        {
            foreach (var error in modelState.Value.Errors)
            {
                Console.WriteLine($"Error in {modelState.Key}: {error.ErrorMessage}");
            }
        }
        return View(player);
    }
}
